EventScript_UseFlash::
	msgbox Text_PlayerUsedLantern, MSGBOX_DEFAULT
	closemessage
	animateflash 1
	setflashlevel 0
	end

	Text_PlayerUsedLantern:
	.string "{PLAYER} used the LANTERN!$"
