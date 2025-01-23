PalletTown_PlayersHouse_1F_MapScripts::
# 2 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PalletTown_PlayersHouse_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	map_script_2 VAR_MOM, 0, Mom_Bye
	.2byte 0


Mom_Bye::
# 8 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	lock
# 9 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	setvar VAR_MOM, 1
# 10 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	applymovement 1, Mom_Bye_Movement_0
# 16 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	waitmovement 1
# 17 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 18 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox Mom_Bye_Text_0, MSGBOX_NPC
# 26 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 27 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	giveitem ITEM_TOWN_MAP
# 28 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	setflag FLAG_SYS_B_DASH
# 29 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox Mom_Bye_Text_1
# 32 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 33 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	applymovement 1, Mom_Bye_Movement_1
# 37 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
	end


# 42 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 43 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
.equ LOCALID_MOM, 1
# 44 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 45 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 46 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_Mom::
# 47 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	lock
# 48 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	faceplayer
# 49 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
# 50 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	checkplayergender
# 51 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
# 52 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
# 53 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 54 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	applymovement LOCALID_MOM, Common_Movement_FaceOriginalDirection
# 55 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	waitmovement 0
# 56 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
# 57 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	end
# 58 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 59 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
# 60 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
# 61 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	return
# 62 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 63 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
# 64 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
# 65 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	return
# 66 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 67 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_MomHeal::
# 68 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
# 69 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	closemessage
# 70 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 71 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
# 72 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	release
# 73 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	end
# 74 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 75 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
@ Displays special text if interacted with from side or back (which are normally inaccessible)
# 76 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_TV::
# 77 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	lockall
# 78 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
# 79 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
# 80 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	releaseall
# 81 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	end
# 82 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 83 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_TVScreen::
# 84 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	checkplayergender
# 85 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
# 86 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
# 87 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	releaseall
# 88 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	end
# 89 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 90 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
# 91 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
# 92 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	return
# 93 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"

# 94 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
# 95 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
# 96 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	return

# 10 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
Mom_Bye_Movement_0:
# 11 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_in_place_up
# 12 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 13 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_up
# 14 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_right
	step_end

# 33 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
Mom_Bye_Movement_1:
# 34 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 34 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_down
# 35 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	walk_left
	step_end

Mom_Bye_Text_0:
# 19 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.string "MOM: Oh, I can't believe it's \nalready time to go! \pGreen is waiting outside- \nBut please take this present first. \pI bought you some new shoes \nand a map, so if you get lost \pyou can just run home, okay?$"

Mom_Bye_Text_1:
# 30 "data//maps/PalletTown_PlayersHouse_1F/scripts.pory"
	.string "Received Running Shoes and\n Town Map!$"
