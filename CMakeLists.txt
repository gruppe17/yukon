cmake_minimum_required(VERSION 3.17.5)
project(yukon C)

set(CMAKE_C_STANDARD 11)


add_executable(yukon main.c deck/deck.c deck/deck.h deck/playingCard.c deck/playingCard.h LinkedList/LinkedList.c LinkedList/LinkedList.h commands/command_utils.h commands/command_utils.c utils/strutils.h utils/strutils.c commands/commands.c commands/commands.h Dictionary/Dictionary.c Dictionary/Dictionary.h game/game.c game/game.h UI/GameView.c UI/GameView.h utils/integerUtils.c utils/integerUtils.h UI/GameViewConstants.h UI/GameViewInternalFunctions.h LinkedList/LinkedListInternalFunctions.h UI/user_input.c UI/user_input.h  UI/user_interface.c UI/user_interface.h)
