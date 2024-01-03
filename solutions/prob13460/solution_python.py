"""
Baekjoon Online Judge #13460
https://www.acmicpc.net/problem/13460
"""

from collections import deque
from enum import Enum
from dataclasses import dataclass
from sys import stdin

infast = lambda: stdin.readline().strip()


@dataclass
class Board:
    rows: int
    cols: int
    grid: list[list[int]]
    hole_pos: tuple[int, int]


@dataclass(frozen=True)
class State:
    red_pos: tuple[int, int]
    blue_pos: tuple[int, int]


class CheckResult(Enum):
    CONTINUE = 0
    SOLVED = 1
    FAIL = 2


def deserialize(grid_raw: list[str], n: int, m: int) -> tuple[Board, State]:
    board = Board(n, m, [], (0, 0))
    red_pos = (-1, -1)
    blue_pos = (-1, -1)
    for y, line in enumerate(grid_raw):
        if "O" in line:
            board.hole_pos = (y, line.index("O"))
        if "R" in line:
            red_pos = (y, line.index("R"))
        if "B" in line:
            blue_pos = (y, line.index("B"))
        board.grid.append([int(c == "#") for c in line])
    return board, State(red_pos, blue_pos)


def transpose(board: Board, state: State) -> tuple[Board, State]:
    new_state = State(
        (state.red_pos[1], state.red_pos[0]), (state.blue_pos[1], state.blue_pos[0])
    )
    new_board = Board(
        board.cols, board.rows, [], (board.hole_pos[1], board.hole_pos[0])
    )
    for x in range(board.cols):
        col = [l[x] for l in board.grid]
        new_board.grid.append(col)
    return new_board, new_state


def flip_lr(board: Board, state: State) -> tuple[Board, State]:
    new_state = State(
        (state.red_pos[0], board.cols - state.red_pos[1] - 1),
        (state.blue_pos[0], board.cols - state.blue_pos[1] - 1),
    )
    new_board = Board(
        board.rows,
        board.cols,
        [],
        (board.hole_pos[0], board.cols - board.hole_pos[1] - 1),
    )
    for line in board.grid:
        new_board.grid.append(line[::-1])
    return new_board, new_state


def tilt_left(board: Board, prev_state: State) -> State:
    red_y, red_x = prev_state.red_pos
    blue_y, blue_x = prev_state.blue_pos

    red_dx = board.grid[red_y][:red_x][::-1].index(1)
    new_red_x = red_x - red_dx
    blue_dx = board.grid[blue_y][:blue_x][::-1].index(1)
    new_blue_x = blue_x - blue_dx

    if red_y == blue_y and new_red_x == new_blue_x:
        if red_x < blue_x:
            new_blue_x += 1
        else:
            new_red_x += 1

    return State((red_y, new_red_x), (blue_y, new_blue_x))


def tilt_right(board: Board, prev_state: State) -> State:
    flipped_board, flipped_state = flip_lr(board, prev_state)
    return flip_lr(flipped_board, tilt_left(flipped_board, flipped_state))[1]


def tilt_up(board: Board, prev_state: State) -> State:
    transposed_board, transposed_state = transpose(board, prev_state)
    return transpose(transposed_board, tilt_left(transposed_board, transposed_state))[1]


def tilt_down(board: Board, prev_state: State) -> State:
    transformed_board, transformed_state = flip_lr(*transpose(board, prev_state))
    return transpose(
        *flip_lr(transformed_board, tilt_left(transformed_board, transformed_state))
    )[1]


def is_vertical_segment(segment: tuple[tuple[int, int], tuple[int, int]]) -> bool:
    start, end = sorted(segment)
    _, start_x = start
    _, end_x = end
    return start_x == end_x


def is_horizontal_segment(segment: tuple[tuple[int, int], tuple[int, int]]) -> bool:
    start, end = sorted(segment)
    start_y, _ = start
    end_y, _ = end
    return start_y == end_y


def point_in_segment(
    point: tuple[int, int], segment: tuple[tuple[int, int], tuple[int, int]]
) -> bool:
    start, end = sorted(segment)
    start_y, start_x = start
    end_y, end_x = end
    point_y, point_x = point
    if start_y == end_y == point_y:
        return start_x <= point_x <= end_x
    elif start_x == end_x == point_x:
        return start_y <= point_y <= end_y
    else:
        return False


def check_fall(board: Board, prev_state: State, next_state: State) -> CheckResult:
    if point_in_segment(board.hole_pos, (prev_state.blue_pos, next_state.blue_pos)):
        return CheckResult.FAIL
    elif point_in_segment(board.hole_pos, (prev_state.red_pos, next_state.red_pos)):
        next_red_y, next_red_x = next_state.red_pos
        if is_vertical_segment(
            (prev_state.red_pos, next_state.red_pos)
        ) and is_vertical_segment((prev_state.blue_pos, next_state.blue_pos)):
            next_blue_y, next_blue_x = next_state.blue_pos
            if prev_state.red_pos <= next_state.red_pos:
                if next_blue_y == next_red_y - 1:
                    next_blue_y += 1
                if point_in_segment(
                    board.hole_pos, (prev_state.blue_pos, (next_blue_y, next_blue_x))
                ):
                    return CheckResult.FAIL
            else:
                if next_blue_y == next_red_y + 1:
                    next_blue_y -= 1
                if point_in_segment(
                    board.hole_pos, (prev_state.blue_pos, (next_blue_y, next_blue_x))
                ):
                    return CheckResult.FAIL
        else:
            next_blue_y, next_blue_x = next_state.blue_pos
            if prev_state.red_pos <= next_state.red_pos:
                if next_blue_x == next_red_x - 1:
                    next_blue_x += 1
                if point_in_segment(
                    board.hole_pos, (prev_state.blue_pos, (next_blue_y, next_blue_x))
                ):
                    return CheckResult.FAIL
            else:
                if next_blue_x == next_red_x + 1:
                    next_blue_x -= 1
                if point_in_segment(
                    board.hole_pos, (prev_state.blue_pos, (next_blue_y, next_blue_x))
                ):
                    return CheckResult.FAIL
        return CheckResult.SOLVED
    else:
        return CheckResult.CONTINUE


N, M = map(int, infast().split())
grid_raw = []
for _ in range(N):
    grid_raw.append(infast())

board, init_state = deserialize(grid_raw, N, M)
q = deque([init_state])
dist = {init_state: 0}
solved = False
while q:
    state = q.popleft()
    next_states = [
        tilt_left(board, state),
        tilt_right(board, state),
        tilt_up(board, state),
        tilt_down(board, state),
    ]
    if dist[state] >= 10:
        break

    for next_state in next_states:
        if next_state in dist:
            continue
        check_result = check_fall(board, state, next_state)
        if check_result == CheckResult.FAIL:
            continue
        elif check_result == CheckResult.SOLVED:
            solved = True
            break
        dist[next_state] = dist[state] + 1
        q.append(next_state)

    if solved:
        print(dist[state] + 1)
        break
if not solved:
    print(-1)
