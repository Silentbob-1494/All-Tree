Pokemon_Center_Littleroot_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Littleroot_PokemonCenter_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


Littleroot_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN
	end


Pokecenter_Employee_Simple::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end


Pokecenter_Employee::
	lock
	faceplayer
	msgbox Pokecenter_Employee_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Pokecenter_Employee_1
	msgbox Pokecenter_Employee_Text_2, MSGBOX_NPC
	return

Pokecenter_Employee_1:
	fadescreen FADE_TO_BLACK
	incrementgamestat GAME_STAT_USED_POKECENTER
	setweather WEATHER_FOG_DIAGONAL
	doweather
	fadescreen FADE_FROM_BLACK
	special HealPlayerParty
	msgbox Pokecenter_Employee_Text_1
	waitmessage
	release
	end


Pokecenter_Employee_Text_0:
	.string "Hey, I got that gooood shit, guaranteed\n"
	.string "to fix you right up. Want some?$"

Pokecenter_Employee_Text_1:
	.string "Come again soon.$"

Pokecenter_Employee_Text_2:
	.string "Let me know if you change your mind$"
