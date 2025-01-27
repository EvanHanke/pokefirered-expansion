PalletTown_MapScripts::
# 5 "data//maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_Init
# 2 "data//maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

PalletTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data//maps/PalletTown/scripts.pory"
	map_script_2 VAR_MOM, 1, PalletTown_Green
	.2byte 0


PalletTown_Init::
# 9 "data//maps/PalletTown/scripts.pory"
	setflag FLAG_TEMP_1
	return


PalletTown_Green::
# 13 "data//maps/PalletTown/scripts.pory"
	lock
# 14 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MOM, 2
# 15 "data//maps/PalletTown/scripts.pory"
	applymovement 4, PalletTown_Green_Movement_0
# 18 "data//maps/PalletTown/scripts.pory"
	waitmovement 4
# 19 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Green_Text_0, MSGBOX_NPC
# 24 "data//maps/PalletTown/scripts.pory"
	waitmessage
# 25 "data//maps/PalletTown/scripts.pory"
	applymovement 4, PalletTown_Green_Movement_1
# 32 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Green_Movement_2
# 38 "data//maps/PalletTown/scripts.pory"
	waitmovement 4
# 39 "data//maps/PalletTown/scripts.pory"
	applymovement 4, PalletTown_Green_Movement_3
# 42 "data//maps/PalletTown/scripts.pory"
	addobject 1
# 43 "data//maps/PalletTown/scripts.pory"
	addobject 2
# 44 "data//maps/PalletTown/scripts.pory"
	addobject 3
# 45 "data//maps/PalletTown/scripts.pory"
	waitmovement 4
# 46 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Green_Text_1, MSGBOX_NPC
# 49 "data//maps/PalletTown/scripts.pory"
	applymovement 4, PalletTown_Green_Movement_4
# 53 "data//maps/PalletTown/scripts.pory"
	setobjectxyperm 4, 7, 14
# 54 "data//maps/PalletTown/scripts.pory"
	release
	end


starter1::
# 59 "data//maps/PalletTown/scripts.pory"
	lock
# 60 "data//maps/PalletTown/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
# 61 "data//maps/PalletTown/scripts.pory"
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
# 62 "data//maps/PalletTown/scripts.pory"
	msgbox starter1_Text_0
# 63 "data//maps/PalletTown/scripts.pory"
	release
# 64 "data//maps/PalletTown/scripts.pory"
	hidemonpic
	end


starter2::
# 68 "data//maps/PalletTown/scripts.pory"
	lock
# 69 "data//maps/PalletTown/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
# 70 "data//maps/PalletTown/scripts.pory"
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
# 71 "data//maps/PalletTown/scripts.pory"
	msgbox starter1_Text_0
# 72 "data//maps/PalletTown/scripts.pory"
	release
# 73 "data//maps/PalletTown/scripts.pory"
	hidemonpic
	end


starter3::
# 77 "data//maps/PalletTown/scripts.pory"
	lock
# 78 "data//maps/PalletTown/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
# 79 "data//maps/PalletTown/scripts.pory"
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
# 80 "data//maps/PalletTown/scripts.pory"
	msgbox starter1_Text_0
# 81 "data//maps/PalletTown/scripts.pory"
	release
# 82 "data//maps/PalletTown/scripts.pory"
	hidemonpic
	end


# 86 "data//maps/PalletTown/scripts.pory"

# 87 "data//maps/PalletTown/scripts.pory"
.equ LOCALID_SIGN_LADY, 1
# 88 "data//maps/PalletTown/scripts.pory"
.equ LOCALID_PROF_OAK,  3
# 89 "data//maps/PalletTown/scripts.pory"

# 90 "data//maps/PalletTown/scripts.pory"
.equ SIGN_LADY_READY, VAR_TEMP_2
# 91 "data//maps/PalletTown/scripts.pory"

# 92 "data//maps/PalletTown/scripts.pory"
PalletTown_OnTransition::
# 93 "data//maps/PalletTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
# 94 "data//maps/PalletTown/scripts.pory"
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
# 95 "data//maps/PalletTown/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0, PalletTown_EventScript_SetSignLadyPos
# 96 "data//maps/PalletTown/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SetSignLadyDone
# 97 "data//maps/PalletTown/scripts.pory"
	end
# 98 "data//maps/PalletTown/scripts.pory"

# 99 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_TryReadySignLady::
# 100 "data//maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_OPENED_START_MENU, EventScript_Return
# 101 "data//maps/PalletTown/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, EventScript_Return
# 102 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 103 "data//maps/PalletTown/scripts.pory"
	return
# 104 "data//maps/PalletTown/scripts.pory"

# 105 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SetSignLadyDone::
# 106 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
# 107 "data//maps/PalletTown/scripts.pory"
	return
# 108 "data//maps/PalletTown/scripts.pory"

# 109 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SetSignLadyPos::
# 110 "data//maps/PalletTown/scripts.pory"
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
# 111 "data//maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_SIGN_LADY, 5, 15
# 112 "data//maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
# 113 "data//maps/PalletTown/scripts.pory"
	return
# 114 "data//maps/PalletTown/scripts.pory"

# 115 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_MoveSignLadyToRouteEntrance::
# 116 "data//maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_SIGN_LADY, 12, 2
# 117 "data//maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
# 118 "data//maps/PalletTown/scripts.pory"
	setvar SIGN_LADY_READY, TRUE
# 119 "data//maps/PalletTown/scripts.pory"
	return
# 120 "data//maps/PalletTown/scripts.pory"

# 121 "data//maps/PalletTown/scripts.pory"
PalletTown_OnFrame::
# 122 "data//maps/PalletTown/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
# 123 "data//maps/PalletTown/scripts.pory"
	.2byte 0
# 124 "data//maps/PalletTown/scripts.pory"

# 125 "data//maps/PalletTown/scripts.pory"
@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
# 126 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakRatingScene::
# 127 "data//maps/PalletTown/scripts.pory"
	lockall
# 128 "data//maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 129 "data//maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 14, 14
# 130 "data//maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
# 131 "data//maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 132 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
# 133 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 134 "data//maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
# 135 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakLetMeSeePokedex
# 136 "data//maps/PalletTown/scripts.pory"
	setvar VAR_0x8004, 0
# 137 "data//maps/PalletTown/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 138 "data//maps/PalletTown/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 139 "data//maps/PalletTown/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 140 "data//maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 141 "data//maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 142 "data//maps/PalletTown/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
# 143 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
# 144 "data//maps/PalletTown/scripts.pory"
	closemessage
# 145 "data//maps/PalletTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 146 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
# 147 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
# 148 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 149 "data//maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 150 "data//maps/PalletTown/scripts.pory"
	waitdooranim
# 151 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 152 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 153 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 154 "data//maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 155 "data//maps/PalletTown/scripts.pory"
	waitdooranim
# 156 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
# 157 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 158 "data//maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 159 "data//maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 160 "data//maps/PalletTown/scripts.pory"
	waitstate
# 161 "data//maps/PalletTown/scripts.pory"
	releaseall
# 162 "data//maps/PalletTown/scripts.pory"
	end
# 163 "data//maps/PalletTown/scripts.pory"

# 164 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_EndOakRatingScene::
# 165 "data//maps/PalletTown/scripts.pory"
	closemessage
# 166 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakExit
# 167 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 168 "data//maps/PalletTown/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 169 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 170 "data//maps/PalletTown/scripts.pory"
	releaseall
# 171 "data//maps/PalletTown/scripts.pory"
	end
# 172 "data//maps/PalletTown/scripts.pory"

# 173 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotEnoughMonsForNationalDex::
# 174 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
# 175 "data//maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 176 "data//maps/PalletTown/scripts.pory"
	end
# 177 "data//maps/PalletTown/scripts.pory"

# 178 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotBeenToOneIslandYet::
# 179 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
# 180 "data//maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 181 "data//maps/PalletTown/scripts.pory"
	end
# 182 "data//maps/PalletTown/scripts.pory"

# 183 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToPlayersDoor::
# 184 "data//maps/PalletTown/scripts.pory"
	walk_left
# 185 "data//maps/PalletTown/scripts.pory"
	walk_left
# 186 "data//maps/PalletTown/scripts.pory"
	walk_left
# 187 "data//maps/PalletTown/scripts.pory"
	walk_up
# 188 "data//maps/PalletTown/scripts.pory"
	walk_up
# 189 "data//maps/PalletTown/scripts.pory"
	walk_up
# 190 "data//maps/PalletTown/scripts.pory"
	walk_up
# 191 "data//maps/PalletTown/scripts.pory"
	walk_up
# 192 "data//maps/PalletTown/scripts.pory"
	walk_left
# 193 "data//maps/PalletTown/scripts.pory"
	walk_left
# 194 "data//maps/PalletTown/scripts.pory"
	walk_left
# 195 "data//maps/PalletTown/scripts.pory"
	walk_left
# 196 "data//maps/PalletTown/scripts.pory"
	walk_left
# 197 "data//maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 198 "data//maps/PalletTown/scripts.pory"
	step_end
# 199 "data//maps/PalletTown/scripts.pory"

# 200 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_OakExit::
# 201 "data//maps/PalletTown/scripts.pory"
	walk_right
# 202 "data//maps/PalletTown/scripts.pory"
	walk_right
# 203 "data//maps/PalletTown/scripts.pory"
	walk_right
# 204 "data//maps/PalletTown/scripts.pory"
	walk_right
# 205 "data//maps/PalletTown/scripts.pory"
	walk_right
# 206 "data//maps/PalletTown/scripts.pory"
	walk_down
# 207 "data//maps/PalletTown/scripts.pory"
	walk_down
# 208 "data//maps/PalletTown/scripts.pory"
	walk_down
# 209 "data//maps/PalletTown/scripts.pory"
	walk_down
# 210 "data//maps/PalletTown/scripts.pory"
	walk_down
# 211 "data//maps/PalletTown/scripts.pory"
	walk_right
# 212 "data//maps/PalletTown/scripts.pory"
	walk_right
# 213 "data//maps/PalletTown/scripts.pory"
	walk_right
# 214 "data//maps/PalletTown/scripts.pory"
	step_end
# 215 "data//maps/PalletTown/scripts.pory"

# 216 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabFromHouse::
# 217 "data//maps/PalletTown/scripts.pory"
	walk_right
# 218 "data//maps/PalletTown/scripts.pory"
	walk_right
# 219 "data//maps/PalletTown/scripts.pory"
	walk_right
# 220 "data//maps/PalletTown/scripts.pory"
	walk_right
# 221 "data//maps/PalletTown/scripts.pory"
	walk_right
# 222 "data//maps/PalletTown/scripts.pory"
	walk_down
# 223 "data//maps/PalletTown/scripts.pory"
	walk_down
# 224 "data//maps/PalletTown/scripts.pory"
	walk_down
# 225 "data//maps/PalletTown/scripts.pory"
	walk_down
# 226 "data//maps/PalletTown/scripts.pory"
	walk_down
# 227 "data//maps/PalletTown/scripts.pory"
	walk_right
# 228 "data//maps/PalletTown/scripts.pory"
	walk_right
# 229 "data//maps/PalletTown/scripts.pory"
	walk_right
# 230 "data//maps/PalletTown/scripts.pory"
	walk_right
# 231 "data//maps/PalletTown/scripts.pory"
	walk_right
# 232 "data//maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 233 "data//maps/PalletTown/scripts.pory"
	step_end
# 234 "data//maps/PalletTown/scripts.pory"

# 235 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabFromHouse::
# 236 "data//maps/PalletTown/scripts.pory"
	walk_down
# 237 "data//maps/PalletTown/scripts.pory"
	walk_right
# 238 "data//maps/PalletTown/scripts.pory"
	walk_right
# 239 "data//maps/PalletTown/scripts.pory"
	walk_right
# 240 "data//maps/PalletTown/scripts.pory"
	walk_right
# 241 "data//maps/PalletTown/scripts.pory"
	walk_right
# 242 "data//maps/PalletTown/scripts.pory"
	walk_down
# 243 "data//maps/PalletTown/scripts.pory"
	walk_down
# 244 "data//maps/PalletTown/scripts.pory"
	walk_down
# 245 "data//maps/PalletTown/scripts.pory"
	walk_down
# 246 "data//maps/PalletTown/scripts.pory"
	walk_down
# 247 "data//maps/PalletTown/scripts.pory"
	walk_right
# 248 "data//maps/PalletTown/scripts.pory"
	walk_right
# 249 "data//maps/PalletTown/scripts.pory"
	walk_right
# 250 "data//maps/PalletTown/scripts.pory"
	walk_right
# 251 "data//maps/PalletTown/scripts.pory"
	step_end
# 252 "data//maps/PalletTown/scripts.pory"

# 253 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerLeft::
# 254 "data//maps/PalletTown/scripts.pory"
	lockall
# 255 "data//maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 0
# 256 "data//maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 257 "data//maps/PalletTown/scripts.pory"
	end
# 258 "data//maps/PalletTown/scripts.pory"

# 259 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerRight::
# 260 "data//maps/PalletTown/scripts.pory"
	lockall
# 261 "data//maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 1
# 262 "data//maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 263 "data//maps/PalletTown/scripts.pory"
	end
# 264 "data//maps/PalletTown/scripts.pory"

# 265 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTrigger::
# 266 "data//maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 267 "data//maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 268 "data//maps/PalletTown/scripts.pory"
	delay 30
# 269 "data//maps/PalletTown/scripts.pory"
	playbgm MUS_OAK, 0
# 270 "data//maps/PalletTown/scripts.pory"
	message PalletTown_Text_OakDontGoOut
# 271 "data//maps/PalletTown/scripts.pory"
	waitmessage
# 272 "data//maps/PalletTown/scripts.pory"
	delay 85
# 273 "data//maps/PalletTown/scripts.pory"
	closemessage
# 274 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 275 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 276 "data//maps/PalletTown/scripts.pory"
	playse SE_PIN
# 277 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 278 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 279 "data//maps/PalletTown/scripts.pory"
	delay 30
# 280 "data//maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 281 "data//maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
# 282 "data//maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
# 283 "data//maps/PalletTown/scripts.pory"
	delay 30
# 284 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
# 285 "data//maps/PalletTown/scripts.pory"
	closemessage
# 286 "data//maps/PalletTown/scripts.pory"
	delay 30
# 287 "data//maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 288 "data//maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 289 "data//maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 290 "data//maps/PalletTown/scripts.pory"
	waitdooranim
# 291 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 292 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 293 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 294 "data//maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 295 "data//maps/PalletTown/scripts.pory"
	waitdooranim
# 296 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 297 "data//maps/PalletTown/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 298 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 299 "data//maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 300 "data//maps/PalletTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 301 "data//maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 302 "data//maps/PalletTown/scripts.pory"
	waitstate
# 303 "data//maps/PalletTown/scripts.pory"
	releaseall
# 304 "data//maps/PalletTown/scripts.pory"
	end
# 305 "data//maps/PalletTown/scripts.pory"

# 306 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterLeft::
# 307 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 308 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 309 "data//maps/PalletTown/scripts.pory"
	return
# 310 "data//maps/PalletTown/scripts.pory"

# 311 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterRight::
# 312 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterRight
# 313 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 314 "data//maps/PalletTown/scripts.pory"
	return
# 315 "data//maps/PalletTown/scripts.pory"

# 316 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabLeft::
# 317 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
# 318 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
# 319 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 320 "data//maps/PalletTown/scripts.pory"
	return
# 321 "data//maps/PalletTown/scripts.pory"

# 322 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabRight::
# 323 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
# 324 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
# 325 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 326 "data//maps/PalletTown/scripts.pory"
	return
# 327 "data//maps/PalletTown/scripts.pory"

# 328 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLeft::
# 329 "data//maps/PalletTown/scripts.pory"
	walk_up
# 330 "data//maps/PalletTown/scripts.pory"
	walk_up
# 331 "data//maps/PalletTown/scripts.pory"
	walk_right
# 332 "data//maps/PalletTown/scripts.pory"
	walk_up
# 333 "data//maps/PalletTown/scripts.pory"
	walk_up
# 334 "data//maps/PalletTown/scripts.pory"
	walk_right
# 335 "data//maps/PalletTown/scripts.pory"
	walk_up
# 336 "data//maps/PalletTown/scripts.pory"
	walk_up
# 337 "data//maps/PalletTown/scripts.pory"
	step_end
# 338 "data//maps/PalletTown/scripts.pory"

# 339 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterRight::
# 340 "data//maps/PalletTown/scripts.pory"
	walk_right
# 341 "data//maps/PalletTown/scripts.pory"
	walk_up
# 342 "data//maps/PalletTown/scripts.pory"
	walk_up
# 343 "data//maps/PalletTown/scripts.pory"
	walk_right
# 344 "data//maps/PalletTown/scripts.pory"
	walk_up
# 345 "data//maps/PalletTown/scripts.pory"
	walk_up
# 346 "data//maps/PalletTown/scripts.pory"
	walk_right
# 347 "data//maps/PalletTown/scripts.pory"
	walk_up
# 348 "data//maps/PalletTown/scripts.pory"
	walk_up
# 349 "data//maps/PalletTown/scripts.pory"
	step_end
# 350 "data//maps/PalletTown/scripts.pory"

# 351 "data//maps/PalletTown/scripts.pory"
	.macro walk_to_lab
# 352 "data//maps/PalletTown/scripts.pory"
	walk_left
# 353 "data//maps/PalletTown/scripts.pory"
	walk_down
# 354 "data//maps/PalletTown/scripts.pory"
	walk_down
# 355 "data//maps/PalletTown/scripts.pory"
	walk_down
# 356 "data//maps/PalletTown/scripts.pory"
	walk_down
# 357 "data//maps/PalletTown/scripts.pory"
	walk_down
# 358 "data//maps/PalletTown/scripts.pory"
	walk_down
# 359 "data//maps/PalletTown/scripts.pory"
	walk_down
# 360 "data//maps/PalletTown/scripts.pory"
	walk_down
# 361 "data//maps/PalletTown/scripts.pory"
	walk_down
# 362 "data//maps/PalletTown/scripts.pory"
	walk_down
# 363 "data//maps/PalletTown/scripts.pory"
	walk_down
# 364 "data//maps/PalletTown/scripts.pory"
	walk_right
# 365 "data//maps/PalletTown/scripts.pory"
	walk_right
# 366 "data//maps/PalletTown/scripts.pory"
	walk_right
# 367 "data//maps/PalletTown/scripts.pory"
	walk_right
# 368 "data//maps/PalletTown/scripts.pory"
	.endm
# 369 "data//maps/PalletTown/scripts.pory"

# 370 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabLeft::
# 371 "data//maps/PalletTown/scripts.pory"
	walk_down
# 372 "data//maps/PalletTown/scripts.pory"
	walk_to_lab
# 373 "data//maps/PalletTown/scripts.pory"
	walk_right
# 374 "data//maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 375 "data//maps/PalletTown/scripts.pory"
	step_end
# 376 "data//maps/PalletTown/scripts.pory"

# 377 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabRight::
# 378 "data//maps/PalletTown/scripts.pory"
	walk_down
# 379 "data//maps/PalletTown/scripts.pory"
	walk_left
# 380 "data//maps/PalletTown/scripts.pory"
	walk_to_lab
# 381 "data//maps/PalletTown/scripts.pory"
	walk_right
# 382 "data//maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 383 "data//maps/PalletTown/scripts.pory"
	step_end
# 384 "data//maps/PalletTown/scripts.pory"

# 385 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLab::
# 386 "data//maps/PalletTown/scripts.pory"
	walk_up
# 387 "data//maps/PalletTown/scripts.pory"
	set_invisible
# 388 "data//maps/PalletTown/scripts.pory"
	step_end
# 389 "data//maps/PalletTown/scripts.pory"

# 390 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabLeft::
# 391 "data//maps/PalletTown/scripts.pory"
	walk_down
# 392 "data//maps/PalletTown/scripts.pory"
	walk_down
# 393 "data//maps/PalletTown/scripts.pory"
	walk_to_lab
# 394 "data//maps/PalletTown/scripts.pory"
	step_end
# 395 "data//maps/PalletTown/scripts.pory"

# 396 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabRight::
# 397 "data//maps/PalletTown/scripts.pory"
	walk_down
# 398 "data//maps/PalletTown/scripts.pory"
	walk_down
# 399 "data//maps/PalletTown/scripts.pory"
	walk_left
# 400 "data//maps/PalletTown/scripts.pory"
	walk_to_lab
# 401 "data//maps/PalletTown/scripts.pory"
	step_end
# 402 "data//maps/PalletTown/scripts.pory"

# 403 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerEnterLab::
# 404 "data//maps/PalletTown/scripts.pory"
	walk_right
# 405 "data//maps/PalletTown/scripts.pory"
	walk_up
# 406 "data//maps/PalletTown/scripts.pory"
	set_invisible
# 407 "data//maps/PalletTown/scripts.pory"
	step_end
# 408 "data//maps/PalletTown/scripts.pory"

# 409 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLady::
# 410 "data//maps/PalletTown/scripts.pory"
	lock
# 411 "data//maps/PalletTown/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2, PalletTown_EventScript_SignLadyDone
# 412 "data//maps/PalletTown/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SignLadyJustShowedSign
# 413 "data//maps/PalletTown/scripts.pory"
	goto_if_eq SIGN_LADY_READY, TRUE, PalletTown_EventScript_SignLadyStartShowSign
# 414 "data//maps/PalletTown/scripts.pory"
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
# 415 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_HmmIsThatRight
# 416 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 417 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 418 "data//maps/PalletTown/scripts.pory"
	playse SE_PIN
# 419 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_ExclamationMark
# 420 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 421 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_Delay48
# 422 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 423 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OhLookLook
# 424 "data//maps/PalletTown/scripts.pory"
	closemessage
# 425 "data//maps/PalletTown/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayRight
# 426 "data//maps/PalletTown/scripts.pory"
	call_if_ne VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayLeft
# 427 "data//maps/PalletTown/scripts.pory"
	copyobjectxytoperm LOCALID_SIGN_LADY
# 428 "data//maps/PalletTown/scripts.pory"
	setflag FLAG_TEMP_2
# 429 "data//maps/PalletTown/scripts.pory"
	release
# 430 "data//maps/PalletTown/scripts.pory"
	end
# 431 "data//maps/PalletTown/scripts.pory"

# 432 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayRight::
# 433 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
# 434 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 435 "data//maps/PalletTown/scripts.pory"
	return
# 436 "data//maps/PalletTown/scripts.pory"

# 437 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
# 438 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
# 439 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 440 "data//maps/PalletTown/scripts.pory"
	return
# 441 "data//maps/PalletTown/scripts.pory"

# 442 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyDone::
# 443 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 444 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 445 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RaisingMonsToo
# 446 "data//maps/PalletTown/scripts.pory"
	release
# 447 "data//maps/PalletTown/scripts.pory"
	end
# 448 "data//maps/PalletTown/scripts.pory"

# 449 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyGoReadSign::
# 450 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 451 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 452 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_ReadItReadIt
# 453 "data//maps/PalletTown/scripts.pory"
	release
# 454 "data//maps/PalletTown/scripts.pory"
	end
# 455 "data//maps/PalletTown/scripts.pory"

# 456 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyJustShowedSign::
# 457 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 458 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 459 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_SignsAreUsefulArentThey
# 460 "data//maps/PalletTown/scripts.pory"
	release
# 461 "data//maps/PalletTown/scripts.pory"
	end
# 462 "data//maps/PalletTown/scripts.pory"

# 463 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayRight::
# 464 "data//maps/PalletTown/scripts.pory"
	walk_right
# 465 "data//maps/PalletTown/scripts.pory"
	walk_in_place_faster_left
# 466 "data//maps/PalletTown/scripts.pory"
	step_end
# 467 "data//maps/PalletTown/scripts.pory"

# 468 "data//maps/PalletTown/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayLeft::
# 469 "data//maps/PalletTown/scripts.pory"
	walk_left
# 470 "data//maps/PalletTown/scripts.pory"
	walk_in_place_faster_right
# 471 "data//maps/PalletTown/scripts.pory"
	step_end
# 472 "data//maps/PalletTown/scripts.pory"

# 473 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_FatMan::
# 474 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
# 475 "data//maps/PalletTown/scripts.pory"
	end
# 476 "data//maps/PalletTown/scripts.pory"

# 477 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_OaksLabSign::
# 478 "data//maps/PalletTown/scripts.pory"
	lockall
# 479 "data//maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, 0
# 480 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab
# 481 "data//maps/PalletTown/scripts.pory"
	releaseall
# 482 "data//maps/PalletTown/scripts.pory"
	end
# 483 "data//maps/PalletTown/scripts.pory"

# 484 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_PlayersHouseSign::
# 485 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
# 486 "data//maps/PalletTown/scripts.pory"
	end
# 487 "data//maps/PalletTown/scripts.pory"

# 488 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_RivalsHouseSign::
# 489 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
# 490 "data//maps/PalletTown/scripts.pory"
	end
# 491 "data//maps/PalletTown/scripts.pory"

# 492 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_TownSign::
# 493 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
# 494 "data//maps/PalletTown/scripts.pory"
	end
# 495 "data//maps/PalletTown/scripts.pory"

# 496 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_TrainerTips::
# 497 "data//maps/PalletTown/scripts.pory"
	lockall
# 498 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenu
# 499 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 500 "data//maps/PalletTown/scripts.pory"
	releaseall
# 501 "data//maps/PalletTown/scripts.pory"
	end
# 502 "data//maps/PalletTown/scripts.pory"

# 503 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyTrigger::
# 504 "data//maps/PalletTown/scripts.pory"
	lockall
# 505 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
# 506 "data//maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 507 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 508 "data//maps/PalletTown/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 509 "data//maps/PalletTown/scripts.pory"
	releaseall
# 510 "data//maps/PalletTown/scripts.pory"
	end
# 511 "data//maps/PalletTown/scripts.pory"

# 512 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyShowSign::
# 513 "data//maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 514 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_LookCopiedTrainerTipsSign
# 515 "data//maps/PalletTown/scripts.pory"
	closemessage
# 516 "data//maps/PalletTown/scripts.pory"
	delay 20
# 517 "data//maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 518 "data//maps/PalletTown/scripts.pory"
	setflag FLAG_OPENED_START_MENU
# 519 "data//maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 520 "data//maps/PalletTown/scripts.pory"
	setvar SIGN_LADY_READY, FALSE
# 521 "data//maps/PalletTown/scripts.pory"
	special SetWalkingIntoSignVars
# 522 "data//maps/PalletTown/scripts.pory"
	special DisableMsgBoxWalkaway
# 523 "data//maps/PalletTown/scripts.pory"
	signmsg
# 524 "data//maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenuCopy
# 525 "data//maps/PalletTown/scripts.pory"
	normalmsg
# 526 "data//maps/PalletTown/scripts.pory"
	return
# 527 "data//maps/PalletTown/scripts.pory"

# 528 "data//maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyStartShowSign::
# 529 "data//maps/PalletTown/scripts.pory"
	applymovement LOCALID_SIGN_LADY, Common_Movement_FacePlayer
# 530 "data//maps/PalletTown/scripts.pory"
	waitmovement 0
# 531 "data//maps/PalletTown/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 532 "data//maps/PalletTown/scripts.pory"
	release
# 533 "data//maps/PalletTown/scripts.pory"
	end

# 15 "data//maps/PalletTown/scripts.pory"
PalletTown_Green_Movement_0:
# 16 "data//maps/PalletTown/scripts.pory"
	walk_up
	step_end

# 25 "data//maps/PalletTown/scripts.pory"
PalletTown_Green_Movement_1:
# 26 "data//maps/PalletTown/scripts.pory"
	walk_down
# 27 "data//maps/PalletTown/scripts.pory"
	walk_left
# 27 "data//maps/PalletTown/scripts.pory"
	walk_left
# 27 "data//maps/PalletTown/scripts.pory"
	walk_left
# 28 "data//maps/PalletTown/scripts.pory"
	walk_down
# 28 "data//maps/PalletTown/scripts.pory"
	walk_down
# 28 "data//maps/PalletTown/scripts.pory"
	walk_down
# 28 "data//maps/PalletTown/scripts.pory"
	walk_down
# 29 "data//maps/PalletTown/scripts.pory"
	walk_right
# 29 "data//maps/PalletTown/scripts.pory"
	walk_right
# 29 "data//maps/PalletTown/scripts.pory"
	walk_right
# 29 "data//maps/PalletTown/scripts.pory"
	walk_right
# 30 "data//maps/PalletTown/scripts.pory"
	walk_in_place_down
	step_end

# 32 "data//maps/PalletTown/scripts.pory"
PalletTown_Green_Movement_2:
# 33 "data//maps/PalletTown/scripts.pory"
	walk_down
# 34 "data//maps/PalletTown/scripts.pory"
	walk_left
# 34 "data//maps/PalletTown/scripts.pory"
	walk_left
# 34 "data//maps/PalletTown/scripts.pory"
	walk_left
# 35 "data//maps/PalletTown/scripts.pory"
	walk_down
# 35 "data//maps/PalletTown/scripts.pory"
	walk_down
# 35 "data//maps/PalletTown/scripts.pory"
	walk_down
# 35 "data//maps/PalletTown/scripts.pory"
	walk_down
# 35 "data//maps/PalletTown/scripts.pory"
	walk_down
# 36 "data//maps/PalletTown/scripts.pory"
	walk_right
# 36 "data//maps/PalletTown/scripts.pory"
	walk_right
# 36 "data//maps/PalletTown/scripts.pory"
	walk_right
	step_end

# 39 "data//maps/PalletTown/scripts.pory"
PalletTown_Green_Movement_3:
# 40 "data//maps/PalletTown/scripts.pory"
	walk_down
	step_end

# 49 "data//maps/PalletTown/scripts.pory"
PalletTown_Green_Movement_4:
# 50 "data//maps/PalletTown/scripts.pory"
	walk_up
# 51 "data//maps/PalletTown/scripts.pory"
	face_down
	step_end

PalletTown_Green_Text_0:
# 19 "data//maps/PalletTown/scripts.pory"
	.string "Green: Hey {PLAYER}! \nare you ready to go? \pI have the pokemon my brother \ngave me. \pCome on, I'll show you.$"

PalletTown_Green_Text_1:
# 46 "data//maps/PalletTown/scripts.pory"
	.string "Green: I have three pokemon, \nso we can each pick one.  \pYou can go first.$"

starter1_Text_0:
# 62 "data//maps/PalletTown/scripts.pory"
	.string "starter$"
