Thecloningfacility_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Thecloningfacility_EventScript_BallDefault
	.byte 0


Thecloningfacility_EventScript_BallDefault::
	setvar NEW_STARTERS, 0
	return


Start_StarterChoose_Sequence::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MeetBlastoise
	waitmovement 0
	msgbox BeginAdventureText
	waitmessage
	closemessage
	applymovement 4, ProfMove
	waitmovement 0
	setvar LITTLEROOT_STATE, 1
	release
	return


Start_StarterChoose_Sequence2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MeetBlastoise2
	waitmovement 0
	goto Start_StarterChoose_Sequence
	return


MeetBlastoise:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MeetBlastoise2:
	walk_left
	step_end

ProfMove:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

StopLeaving::
	lockall
	msgbox StopLeaving_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, DoNotLeave
	waitmovement 0
	releaseall
	return


DoNotLeave:
	walk_up
	step_end

Thecloningfacility_EventScript_PBlastoise::
	goto_if_unset FLAG_POKEBALL_ONE, Thecloningfacility_EventScript_PBlastoise_3
Thecloningfacility_EventScript_PBlastoise_2:
	goto_if_set FLAG_SYS_POKEDEX_GET, Thecloningfacility_EventScript_PBlastoise_20
Thecloningfacility_EventScript_PBlastoise_18:
	goto_if_set FLAG_SYS_POKEDEX_GET, Thecloningfacility_EventScript_PBlastoise_17
	return

Thecloningfacility_EventScript_PBlastoise_1:
	lock
	faceplayer
	message Thecloningfacility_EventScript_PBlastoise_Text_0
	multichoice 25, 5, MULTI_1RST_2ND_3RD_CHOICE, 0
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq Thecloningfacility_EventScript_PBlastoise_9
	compare VAR_RESULT, 1
	goto_if_eq Thecloningfacility_EventScript_PBlastoise_10
	compare VAR_RESULT, 2
	goto_if_eq Thecloningfacility_EventScript_PBlastoise_11
Thecloningfacility_EventScript_PBlastoise_8:
	msgbox Thecloningfacility_EventScript_PBlastoise_Text_1
	waitmessage
	release
	return

Thecloningfacility_EventScript_PBlastoise_3:
	goto_if_unset FLAG_POKEBALL_TWO, Thecloningfacility_EventScript_PBlastoise_5
	goto Thecloningfacility_EventScript_PBlastoise_2

Thecloningfacility_EventScript_PBlastoise_5:
	goto_if_unset FLAG_POKEBALL_THREE, Thecloningfacility_EventScript_PBlastoise_1
	goto Thecloningfacility_EventScript_PBlastoise_2

Thecloningfacility_EventScript_PBlastoise_9:
	call Starterfade
	setvar NEW_STARTERS, 0
	goto Thecloningfacility_EventScript_PBlastoise_8

Thecloningfacility_EventScript_PBlastoise_10:
	call Starterfade
	setvar NEW_STARTERS, 1
	goto Thecloningfacility_EventScript_PBlastoise_8

Thecloningfacility_EventScript_PBlastoise_11:
	call Starterfade
	setvar NEW_STARTERS, 2
	goto Thecloningfacility_EventScript_PBlastoise_8

Thecloningfacility_EventScript_PBlastoise_15:
	msgbox Thecloningfacility_EventScript_PBlastoise_Text_2
	call UpgradeNationalDex
	msgbox Thecloningfacility_EventScript_PBlastoise_Text_3
	closemessage
	end

Thecloningfacility_EventScript_PBlastoise_16:
	msgbox Thecloningfacility_EventScript_PBlastoise_Text_3
	closemessage
	end

Thecloningfacility_EventScript_PBlastoise_17:
	goto_if_set FLAG_SYS_NATIONAL_DEX, Thecloningfacility_EventScript_PBlastoise_16
	return

Thecloningfacility_EventScript_PBlastoise_20:
	goto_if_unset FLAG_SYS_NATIONAL_DEX, Thecloningfacility_EventScript_PBlastoise_15
	goto Thecloningfacility_EventScript_PBlastoise_18


Starterfade::
	fadescreen FADE_TO_BLACK
	delay 20
	fadescreen FADE_FROM_BLACK
	return


Thecloningfacility_EventScript_PokeballOne::
	lockall
	setvar VAR_TEMP_0, 1
	goto_if_unset FLAG_POKEBALL_ONE, Thecloningfacility_EventScript_PokeballOne_4
Thecloningfacility_EventScript_PokeballOne_3:
	msgbox Thecloningfacility_EventScript_PokeballOne_Text_0
Thecloningfacility_EventScript_PokeballOne_1:
	waitmessage
	releaseall
	end

Thecloningfacility_EventScript_PokeballOne_2:
	compare NEW_STARTERS, 0
	goto_if_eq Thecloningfacility_EventScript_PokeballOne_9
	compare NEW_STARTERS, 1
	goto_if_eq Thecloningfacility_EventScript_PokeballOne_10
	compare NEW_STARTERS, 2
	goto_if_eq Thecloningfacility_EventScript_PokeballOne_11
	goto Thecloningfacility_EventScript_PokeballOne_1

Thecloningfacility_EventScript_PokeballOne_4:
	goto_if_unset FLAG_POKEBALL_TWO, Thecloningfacility_EventScript_PokeballOne_6
	goto Thecloningfacility_EventScript_PokeballOne_3

Thecloningfacility_EventScript_PokeballOne_6:
	goto_if_unset FLAG_POKEBALL_THREE, Thecloningfacility_EventScript_PokeballOne_2
	goto Thecloningfacility_EventScript_PokeballOne_3

Thecloningfacility_EventScript_PokeballOne_9:
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	setvar STARTER_CHOICE, SPECIES_EEVEE
	call Thecloningfacility_EventScript_GiveStarter_1
	goto Thecloningfacility_EventScript_PokeballOne_1

Thecloningfacility_EventScript_PokeballOne_10:
	bufferspeciesname STR_VAR_1, SPECIES_VAPOREON
	setvar STARTER_CHOICE, SPECIES_VAPOREON
	call Thecloningfacility_EventScript_GiveStarter_1
	goto Thecloningfacility_EventScript_PokeballOne_1

Thecloningfacility_EventScript_PokeballOne_11:
	bufferspeciesname STR_VAR_1, SPECIES_JOLTEON
	setvar STARTER_CHOICE, SPECIES_JOLTEON
	call Thecloningfacility_EventScript_GiveStarter_1
	goto Thecloningfacility_EventScript_PokeballOne_1


Thecloningfacility_EventScript_PokeballTwo::
	lockall
	setvar VAR_TEMP_0, 2
	goto_if_unset FLAG_POKEBALL_ONE, Thecloningfacility_EventScript_PokeballTwo_4
Thecloningfacility_EventScript_PokeballTwo_3:
	msgbox Thecloningfacility_EventScript_PokeballOne_Text_0
Thecloningfacility_EventScript_PokeballTwo_1:
	waitmessage
	releaseall
	end

Thecloningfacility_EventScript_PokeballTwo_2:
	compare NEW_STARTERS, 0
	goto_if_eq Thecloningfacility_EventScript_PokeballTwo_9
	compare NEW_STARTERS, 1
	goto_if_eq Thecloningfacility_EventScript_PokeballTwo_10
	compare NEW_STARTERS, 2
	goto_if_eq Thecloningfacility_EventScript_PokeballTwo_11
	goto Thecloningfacility_EventScript_PokeballTwo_1

Thecloningfacility_EventScript_PokeballTwo_4:
	goto_if_unset FLAG_POKEBALL_TWO, Thecloningfacility_EventScript_PokeballTwo_6
	goto Thecloningfacility_EventScript_PokeballTwo_3

Thecloningfacility_EventScript_PokeballTwo_6:
	goto_if_unset FLAG_POKEBALL_THREE, Thecloningfacility_EventScript_PokeballTwo_2
	goto Thecloningfacility_EventScript_PokeballTwo_3

Thecloningfacility_EventScript_PokeballTwo_9:
	bufferspeciesname STR_VAR_1, SPECIES_FLAREON
	setvar STARTER_CHOICE, SPECIES_FLAREON
	call Thecloningfacility_EventScript_GiveStarter_2
	goto Thecloningfacility_EventScript_PokeballTwo_1

Thecloningfacility_EventScript_PokeballTwo_10:
	bufferspeciesname STR_VAR_1, SPECIES_UMBREON
	setvar STARTER_CHOICE, SPECIES_UMBREON
	call Thecloningfacility_EventScript_GiveStarter_2
	goto Thecloningfacility_EventScript_PokeballTwo_1

Thecloningfacility_EventScript_PokeballTwo_11:
	bufferspeciesname STR_VAR_1, SPECIES_LEAFEON
	setvar STARTER_CHOICE, SPECIES_LEAFEON
	call Thecloningfacility_EventScript_GiveStarter_2
	goto Thecloningfacility_EventScript_PokeballTwo_1


Thecloningfacility_EventScript_PokeballThree::
	lockall
	setvar VAR_TEMP_0, 3
	goto_if_unset FLAG_POKEBALL_ONE, Thecloningfacility_EventScript_PokeballThree_4
Thecloningfacility_EventScript_PokeballThree_3:
	msgbox Thecloningfacility_EventScript_PokeballOne_Text_0
Thecloningfacility_EventScript_PokeballThree_1:
	waitmessage
	releaseall
	end

Thecloningfacility_EventScript_PokeballThree_2:
	compare NEW_STARTERS, 0
	goto_if_eq Thecloningfacility_EventScript_PokeballThree_9
	compare NEW_STARTERS, 1
	goto_if_eq Thecloningfacility_EventScript_PokeballThree_10
	compare NEW_STARTERS, 2
	goto_if_eq Thecloningfacility_EventScript_PokeballThree_11
	goto Thecloningfacility_EventScript_PokeballThree_1

Thecloningfacility_EventScript_PokeballThree_4:
	goto_if_unset FLAG_POKEBALL_TWO, Thecloningfacility_EventScript_PokeballThree_6
	goto Thecloningfacility_EventScript_PokeballThree_3

Thecloningfacility_EventScript_PokeballThree_6:
	goto_if_unset FLAG_POKEBALL_THREE, Thecloningfacility_EventScript_PokeballThree_2
	goto Thecloningfacility_EventScript_PokeballThree_3

Thecloningfacility_EventScript_PokeballThree_9:
	bufferspeciesname STR_VAR_1, SPECIES_SYLVEON
	setvar STARTER_CHOICE, SPECIES_SYLVEON
	call Thecloningfacility_EventScript_GiveStarter_3
	goto Thecloningfacility_EventScript_PokeballThree_1

Thecloningfacility_EventScript_PokeballThree_10:
	bufferspeciesname STR_VAR_1, SPECIES_GLACEON
	setvar STARTER_CHOICE, SPECIES_GLACEON
	call Thecloningfacility_EventScript_GiveStarter_3
	goto Thecloningfacility_EventScript_PokeballThree_1

Thecloningfacility_EventScript_PokeballThree_11:
	bufferspeciesname STR_VAR_1, SPECIES_ESPEON
	setvar STARTER_CHOICE, SPECIES_ESPEON
	call Thecloningfacility_EventScript_GiveStarter_3
	goto Thecloningfacility_EventScript_PokeballThree_1


Thecloningfacility_EventScript_GiveStarter_1::
	showmonpic STARTER_CHOICE, 10, 3
	msgbox Ball_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_1_1
	hidemonpic
	msgbox Thecloningfacility_NotChosen
	return

Thecloningfacility_EventScript_GiveStarter_1_1:
	setflag FLAG_SYS_POKEMON_GET
	setvar LITTLEROOT_STATE, 2
	givemon STARTER_CHOICE, 5, ITEM_LEFTOVERS
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_1_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_1_6
	hidemonpic
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_2
Thecloningfacility_EventScript_GiveStarter_1_4:
	closemessage
	call InitiatePokedexSequence
	return

Thecloningfacility_EventScript_GiveStarter_1_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_0
	removeobject VAR_TEMP_0
	call SetBallFlag
	call NicknamePartyMon
	goto Thecloningfacility_EventScript_GiveStarter_1_4

Thecloningfacility_EventScript_GiveStarter_1_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_0
	removeobject VAR_TEMP_0
	call SetBallFlag
	call NicknameBoxMon
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_1
	goto Thecloningfacility_EventScript_GiveStarter_1_4


Thecloningfacility_EventScript_GiveStarter_2::
	showmonpic STARTER_CHOICE, 10, 3
	msgbox Ball_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_2_1
	hidemonpic
	msgbox Thecloningfacility_NotChosen
	return

Thecloningfacility_EventScript_GiveStarter_2_1:
	setflag FLAG_SYS_POKEMON_GET
	setvar LITTLEROOT_STATE, 2
	givemon STARTER_CHOICE, 5, ITEM_AMULET_COIN
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_2_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_2_6
	hidemonpic
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_2
Thecloningfacility_EventScript_GiveStarter_2_4:
	closemessage
	call InitiatePokedexSequence
	return

Thecloningfacility_EventScript_GiveStarter_2_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_0
	removeobject VAR_TEMP_0
	call SetBallFlag
	call NicknamePartyMon
	goto Thecloningfacility_EventScript_GiveStarter_2_4

Thecloningfacility_EventScript_GiveStarter_2_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_0
	removeobject VAR_TEMP_0
	call SetBallFlag
	call NicknameBoxMon
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_1
	goto Thecloningfacility_EventScript_GiveStarter_2_4


Thecloningfacility_EventScript_GiveStarter_3::
	showmonpic STARTER_CHOICE, 10, 3
	msgbox Ball_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_3_1
	hidemonpic
	msgbox Thecloningfacility_NotChosen
	return

Thecloningfacility_EventScript_GiveStarter_3_1:
	setflag FLAG_SYS_POKEMON_GET
	setvar LITTLEROOT_STATE, 2
	givemon STARTER_CHOICE, 5, ITEM_SHELL_BELL
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_3_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Thecloningfacility_EventScript_GiveStarter_3_6
	hidemonpic
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_2
Thecloningfacility_EventScript_GiveStarter_3_4:
	closemessage
	call InitiatePokedexSequence
	return

Thecloningfacility_EventScript_GiveStarter_3_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_0
	removeobject VAR_TEMP_0
	call SetBallFlag
	call NicknamePartyMon
	goto Thecloningfacility_EventScript_GiveStarter_3_4

Thecloningfacility_EventScript_GiveStarter_3_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_0
	removeobject VAR_TEMP_0
	call SetBallFlag
	call NicknameBoxMon
	msgbox Thecloningfacility_EventScript_GiveStarter_1_Text_1
	goto Thecloningfacility_EventScript_GiveStarter_3_4


SetBallFlag::
	compare VAR_TEMP_0, 1
	goto_if_eq SetBallFlag_2
	compare VAR_TEMP_0, 2
	goto_if_eq SetBallFlag_5
	compare VAR_TEMP_0, 3
	goto_if_eq SetBallFlag_7
	return

SetBallFlag_2:
	setflag FLAG_POKEBALL_ONE
	return

SetBallFlag_5:
	setflag FLAG_POKEBALL_TWO
	return

SetBallFlag_7:
	setflag FLAG_POKEBALL_THREE
	return


DontTouchThat::
	lockall
	msgbox DontTouchThat_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, MoveAwayFromThere
	waitmovement 0
	releaseall
	return


MoveAwayFromThere:
	walk_left
	walk_left
	step_end

NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


InitiatePokedexSequence::
	lock
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, TurnToProf
	applymovement 4, MoveBallOne
	waitmovement 0
	delay 20
	call GivePokedex
	call UpgradeNationalDex
	release
	return


GivePokedex::
	lock
	msgbox TakePokedex, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message GivePokedex_Text_0
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_ADVENTURE_STARTED
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	msgbox GivePokedex_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	msgbox GivePokedex_Text_2, MSGBOX_DEFAULT
	waitmessage
	release
	return


MoveBallOne:
	walk_down
	walk_down
	step_end

TurnToProf:
	face_right
	step_end

UpgradeNationalDex::
	lock
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	msgbox UpgradeNationalDex_Text_0
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	closemessage
	release
	return


StopLeaving_Text_0:
	.string "I guess you don't wanna play this game,\n"
	.string "then.$"

Thecloningfacility_EventScript_PBlastoise_Text_0:
	.string "Well, what do you want?$"

Thecloningfacility_EventScript_PBlastoise_Text_1:
	.string "JEEZ, Just PICK ONE ALREADY!$"

Thecloningfacility_EventScript_PBlastoise_Text_2:
	.string "Cool. Off you fuck now. actually, wait,\n"
	.string "as a matter of fact, hang on. Take this\l"
	.string "too since you're here.$"

Thecloningfacility_EventScript_PBlastoise_Text_3:
	.string "Alright, go run amuck, ya lil bastard :)$"

Thecloningfacility_EventScript_PokeballOne_Text_0:
	.string "Don't be a greedy fuck!$"

Thecloningfacility_EventScript_GiveStarter_1_Text_0:
	.string "Recieved {STR_VAR_1}$"

Thecloningfacility_EventScript_GiveStarter_1_Text_1:
	.string "Transferred {STR_VAR_1} to the dungeon, I mean PC$"

Thecloningfacility_EventScript_GiveStarter_1_Text_2:
	.string "No More Room.$"

DontTouchThat_Text_0:
	.string "DON'T TOUCH THAT! WHAT'S WRONG WITH YOU?$"

NicknamePartyMon_Text_0:
	.string "Give this little turd a nickname?$"

NicknameBoxMon_Text_0:
	.string "Transferred to the Dungeon, I mean PC.$"

GivePokedex_Text_0:
	.string "{PLAYER} received the POKéDEX!$"

GivePokedex_Text_1:
	.string "Also take these with you$"

GivePokedex_Text_2:
	.string "These allow you to trap and enslave\n"
	.string "your own Pokemon in tall grass so you\l"
	.string "can collect research for me.$"

UpgradeNationalDex_Text_0:
	.string "I figured I might as well since you're\n"
	.string "here.$"

BeginAdventureText::
	.string "Hello {PLAYER}, my name is Professor\n"
	.string "Blastoise This is my cloning facility.\l"
	.string "This is where I play god. Do you want\l"
	.string "one of my abominations? Choose wisely\p"
	.string "{COLOR RED}{SHADOW LIGHT_RED}It could mean your ass if you don't.\n"
	.string "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Come talk to me if you want more\l"
	.string "options.$"

Ball_1::
	.string "Do you want this little shit?$"

Ball_2::
	.string "Perhaps I might interest you in this lil\n"
	.string "fucker?$"

Ball_3::
	.string "Do you want this one? It only murdered\n"
	.string "one child.$"

Thecloningfacility_NotChosen::
	.string "No? Well fuck you too, then.$"

TakePokedex::
	.string "The other day I was thinking to myself\n"
	.string "that I should go and hunt down every\l"
	.string "pokemon and catalog it, then I thought\l"
	.string "to myself, 'why bother? I'll get some\l"
	.string "dumb kid to go do it.' And that brings\l"
	.string "me to you, {PLAYER}. If you come back\l"
	.string "without all of them I'll eat you.$"
