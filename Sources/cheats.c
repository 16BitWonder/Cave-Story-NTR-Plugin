#include "cheats.h"
#include "hid.h"

char	*builder_name = "8BitWonder";

//Determine region differences, defaults to USA
u32	general_region_difference = 0x00;
u32	weapon_region_difference = 0x00;
u32 control_region_difference = 0x00;

void	determine_region_diff(u32 tid)
{
	if (tid == 0x098900) //EUR
	{
		general_region_difference = 0x0011F94;
		weapon_region_difference = 0x0011F54;
		control_region_difference = 0x0011F74;
	}
	else if (tid == 0x179A00) //JPN
	{
		general_region_difference = 0x003B618;
		weapon_region_difference = 0x001B59C;
		control_region_difference = 0x003B5F8;
	}
	else if (tid == 0x1A5500) //KOR
	{
		general_region_difference = 0x003C3C0;
		weapon_region_difference = 0x001C344;
		control_region_difference = 0x003C3A0;
	}
}

//Ammunition Codes

void	set_max_missiles(void)
{
	//Read current max missiles
	u16 maxMissiles = READU16(0x01BDF68 + weapon_region_difference);
	//Write max missiles
	if (is_pressed(L))
		WRITEU16(0x01BDF6C + weapon_region_difference, maxMissiles);
}

void	bottomless_missiles(void)
{
	//Read current max missiles
	u16 maxMissiles = READU16(0x01BDF68 + weapon_region_difference);
	WRITEU16(0x01BDF6C + weapon_region_difference, maxMissiles);
}

void	bottomless_bubbline(void)
{
	//Write max bubbline ammo
	WRITEU16(0x01BDF94 + weapon_region_difference, 0x64);
}

void	bottomless_machinegun(void)
{
	//Write max machinegun ammo
	WRITEU16(0x01BDF58 + weapon_region_difference, 0x64);
}

//Health

void	set_max_health(void)
{
	//Read current max health
	u16 maxHealth = READU16(0x01C3B64 + general_region_difference);
	//Write max health
	if (is_pressed(R))
		WRITEU16(0x01C3B60 + general_region_difference, maxHealth);
}

void	invincibility(void)
{
	WRITEU16(0x01C3B60 + general_region_difference, 0xFF);
}

//Weapon Charge

void	all_lvl3_charge(void)
{
	//Except for blade/nemesis
	bubbline_lvl3_charge();
	fireball_lvl3_charge();
	missilelauncher_lvl3_charge();
	pstar_lvl3_charge();
}

void	all_lvl2_charge(void)
{
	//Except for blade/nemesis
	bubbline_lvl2_charge();
	fireball_lvl2_charge();
	missilelauncher_lvl2_charge();
	pstar_lvl2_charge();
}

void	all_lvl1_charge(void)
{
	//Except for blade/nemesis
	bubbline_lvl1_charge();
	fireball_lvl1_charge();
	missilelauncher_lvl1_charge();
	pstar_lvl1_charge();
}

void	blade_max_charge(void)
{
	//Set to lvl3
	WRITEU16(0x01BDF9C + weapon_region_difference, 0x03);
	//Max charge meter
	WRITEU16(0x01BDFA0 + weapon_region_difference, 0x00);
}

void	blade_lvl3_charge(void)
{
	WRITEU16(0x01BDF9C + weapon_region_difference, 0x03);
	WRITEU16(0x01BDFA0 + weapon_region_difference, 0x00);
}

void	blade_lvl2_charge(void)
{
	WRITEU16(0x01BDF9C + weapon_region_difference, 0x02);
	WRITEU16(0x01BDFA0 + weapon_region_difference, 0x00);
}

void	blade_lvl1_charge(void)
{
	WRITEU16(0x01BDF9C + weapon_region_difference, 0x01);
	WRITEU16(0x01BDFA0 + weapon_region_difference, 0x00);
}

void	bubbline_max_charge(void)
{
	//Set to lvl3
	WRITEU16(0x01BDF88 + weapon_region_difference, 0x03);
	//Max charge meter
	WRITEU16(0x01BDF8C + weapon_region_difference, 0x05);
}

void	bubbline_lvl3_charge(void)
{
	WRITEU16(0x01BDF88 + weapon_region_difference, 0x03);
	WRITEU16(0x01BDF8C + weapon_region_difference, 0x00);
}

void	bubbline_lvl2_charge(void)
{
	WRITEU16(0x01BDF88 + weapon_region_difference, 0x02);
	WRITEU16(0x01BDF8C + weapon_region_difference, 0x00);
}

void	bubbline_lvl1_charge(void)
{
	WRITEU16(0x01BDF88 + weapon_region_difference, 0x01);
	WRITEU16(0x01BDF8C + weapon_region_difference, 0x00);
}

void	fireball_max_charge(void)
{
	//Set to lvl3
	WRITEU16(0x01BDF74 + weapon_region_difference, 0x03);
	//Max charge meter
	WRITEU16(0x01BDF78 + weapon_region_difference, 0x14);
}

void	fireball_lvl3_charge(void)
{
	WRITEU16(0x01BDF74 + weapon_region_difference, 0x03);
	WRITEU16(0x01BDF78 + weapon_region_difference, 0x00);
}

void	fireball_lvl2_charge(void)
{
	WRITEU16(0x01BDF74 + weapon_region_difference, 0x02);
	WRITEU16(0x01BDF78 + weapon_region_difference, 0x00);
}

void	fireball_lvl1_charge(void)
{
	WRITEU16(0x01BDF74 + weapon_region_difference, 0x01);
	WRITEU16(0x01BDF78 + weapon_region_difference, 0x00);
}

void	missilelauncher_max_charge(void)
{
	//Set to lvl3
	WRITEU16(0x01BDF60 + weapon_region_difference, 0x03);
	//Max charge meter
	WRITEU16(0x01BDF64 + weapon_region_difference, 0x0A);
}

void	missilelauncher_lvl3_charge(void)
{
	WRITEU16(0x01BDF60 + weapon_region_difference, 0x03);
	WRITEU16(0x01BDF64 + weapon_region_difference, 0x00);
}

void	missilelauncher_lvl2_charge(void)
{
	WRITEU16(0x01BDF60 + weapon_region_difference, 0x02);
	WRITEU16(0x01BDF64 + weapon_region_difference, 0x00);
}

void	missilelauncher_lvl1_charge(void)
{
	WRITEU16(0x01BDF60 + weapon_region_difference, 0x01);
	WRITEU16(0x01BDF64 + weapon_region_difference, 0x00);
}

void	nemesis_max_charge(void)
{
	//Set to lvl3
	WRITEU16(0x01BDF9C + weapon_region_difference, 0x03);
	//Max charge meter
	WRITEU16(0x01BDFA0 + weapon_region_difference, 0x01);
}

void	pstar_max_charge(void)
{
	//Set to lvl3
	WRITEU16(0x01BDF4C + weapon_region_difference, 0x03);
	//Max charge meter
	WRITEU16(0x01BDF50 + weapon_region_difference, 0x0A);
}

void	pstar_lvl3_charge(void)
{
	WRITEU16(0x01BDF4C + weapon_region_difference, 0x03);
	WRITEU16(0x01BDF50 + weapon_region_difference, 0x00);
}

void	pstar_lvl2_charge(void)
{
	WRITEU16(0x01BDF4C + weapon_region_difference, 0x02);
	WRITEU16(0x01BDF50 + weapon_region_difference, 0x00);
}

void	pstar_lvl1_charge(void)
{
	WRITEU16(0x01BDF4C + weapon_region_difference, 0x01);
	WRITEU16(0x01BDF50 + weapon_region_difference, 0x00);
}

void	snake_max_charge(void)
{
	//Set to lvl3
	WRITEU16(0x01BDF4C + weapon_region_difference, 0x03);
	//Max charge meter
	WRITEU16(0x01BDF50 + weapon_region_difference, 0x10);
}

void	spur_max_charge(void)
{
	//Set to lvl3
	WRITEU16(0x01BDF4C + weapon_region_difference, 0x03);
	//Max charge meter
	WRITEU16(0x01BDF50 + weapon_region_difference, 0xC8);
}

//Miscellaneous

void	faster_movement(void)
{
	/*
	Since I can't get Circle-Pad to work normally:
		D-Pad offset: 0x01C3628
			  UpLeft - 60
			    Left - 20
			DownLeft - A0
			 UpRight - 50
			   Right - 10
		   DownRight - 90
		Circle-Pad offset: 0x01C362B
			  UpLeft - 60
			    Left - 20
			DownLeft - A0
			 UpRight - 50
			   Right - 10
		   DownRight - 90
	*/
	
	u16 readDPad = READU16(0x01C3628 + control_region_difference);
	u16 readCPad = READU16(0x01C362B + control_region_difference);
	
	if (readDPad == 0x60 || readDPad == 0x20 || readDPad == 0xA0 || readCPad == 0x60 || readCPad == 0x20 || readCPad == 0xA0)
	{
		//Faster left movement
		WRITEU32(0x01C3B00 + general_region_difference, 0xF0000000);
	}
	if (readDPad == 0x50 || readDPad == 0x10 || readDPad == 0x90 || readCPad == 0x50 || readCPad == 0x10 || readCPad == 0x90)
	{
		//Faster right movement
		WRITEU32(0x01C3B00 + general_region_difference, 0x0F000000);
	}
}

void	infinite_air(void)
{
	//Keep air maxed
	WRITEU16(0x01C3B70 + general_region_difference, 0x3E8);
}

void	infinite_booster(void)
{
	//Keep booster fuel filled
	WRITEU16(0x01C3B7C + general_region_difference, 0x32);
}

void	infinite_jump(void)
{
	if (is_pressed(B) || is_pressed(X))
	{
		//Make game think player is on ground
		WRITEU16(0x01C3AD0 + general_region_difference, 0x08);
	}
}

void	masochist_mode(void)
{
	//Keep health at 1
	WRITEU16(0x01C3B60 + general_region_difference, 0x01);
	//Keep missiles at 0
	WRITEU16(0x01BDF6C + weapon_region_difference, 0x00);
	//Handle weapon charges, all min (Except for blade and nemesis)
	bubbline_lvl1_charge();
	fireball_lvl1_charge();
	missilelauncher_lvl1_charge();
	pstar_lvl1_charge();
}