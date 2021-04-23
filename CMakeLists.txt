cmake_minimum_required(VERSION 3.17.5)
project(yukon C)

set(CMAKE_C_STANDARD 11)


add_executable(yukon main.c deck/deck.c deck/deck.h deck/playingCard.c deck/playingCard.h LinkedList/LinkedList.c LinkedList/LinkedList.h commands/command_ui.h commands/command_ui.c utils/strutils.h utils/strutils.c commands/commands.c commands/commands.h)
