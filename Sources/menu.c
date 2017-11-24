#include "cheats.h"
#include "notes.h"

int setup = 1;

void	my_menus(void)
{
	int index;
	int i;
	
	set_hid_address(0x10002000);
	
	//Begin Region Detection
	if (setup == 1)
	{
		u32 tid = get_tid_low();
		
		determine_region_diff(tid);
		
		setup = 0;
	}
	//End Region Detection
	
	new_spoiler("Ammunition");
		new_entry("Set Max Missiles (L)", set_max_missiles);
		new_entry("Bottomless Missiles", bottomless_missiles);
		new_entry("Bottomless Bubbline", bottomless_bubbline);
		new_entry("Bottomless Machine Gun", bottomless_machinegun);
	exit_spoiler();
	new_spoiler("Health");
		new_entry("Set Max Health (R)", set_max_health);
		new_entry("Invincibility", invincibility);
	exit_spoiler();
	new_spoiler("Weapon Charge");
		new_spoiler("All");
			new_entry("Maintain lvl3 Charge", all_lvl3_charge);
			new_entry("Maintain lvl2 Charge", all_lvl2_charge);
			new_entry("Maintain lvl1 Charge", all_lvl1_charge);
		new_spoiler("Blade");
			new_entry("Maintain Max Charge", blade_max_charge);
			new_entry("Maintain lvl3 Charge", blade_lvl3_charge);
			new_entry("Maintain lvl2 Charge", blade_lvl2_charge);
			new_entry("Maintain lvl1 Charge", blade_lvl1_charge);
		exit_spoiler();
		new_spoiler("Bubbline");
			new_entry("Maintain Max Charge", bubbline_max_charge);
			new_entry("Maintain lvl3 Charge", bubbline_lvl3_charge);
			new_entry("Maintain lvl2 Charge", bubbline_lvl2_charge);
			new_entry("Maintain lvl1 Charge", bubbline_lvl1_charge);
		exit_spoiler();
		new_spoiler("Fireball");
			new_entry("Maintain Max Charge", fireball_max_charge);
			new_entry("Maintain lvl3 Charge", fireball_lvl3_charge);
			new_entry("Maintain lvl2 Charge", fireball_lvl2_charge);
			new_entry("Maintain lvl1 Charge", fireball_lvl1_charge);
		exit_spoiler();
		new_spoiler("Machine Gun");
			new_entry("Maintain Max Charge", pstar_max_charge);
			new_entry("Maintain lvl3 Charge", pstar_lvl3_charge);
			new_entry("Maintain lvl2 Charge", pstar_lvl2_charge);
			new_entry("Maintain lvl1 Charge", pstar_lvl1_charge);
		exit_spoiler();
		new_spoiler("Missile Launcher");
			new_entry("Maintain Max Charge", missilelauncher_max_charge);
			new_entry("Maintain lvl3 Charge", missilelauncher_lvl3_charge);
			new_entry("Maintain lvl2 Charge", missilelauncher_lvl2_charge);
			new_entry("Maintain lvl1 Charge", missilelauncher_lvl1_charge);
		exit_spoiler();
		new_spoiler("Nemesis");
			new_entry("Maintain Max Charge", nemesis_max_charge);
			new_entry("Maintain lvl3 Charge", blade_lvl3_charge);
			new_entry("Maintain lvl2 Charge", blade_lvl2_charge);
			new_entry("Maintain lvl1 Charge", blade_lvl1_charge);
		exit_spoiler();
		new_spoiler("Polar Star");
			new_entry("Maintain Max Charge", pstar_max_charge);
			new_entry("Maintain lvl3 Charge", pstar_lvl3_charge);
			new_entry("Maintain lvl2 Charge", pstar_lvl2_charge);
			new_entry("Maintain lvl1 Charge", pstar_lvl1_charge);
		exit_spoiler();
		new_spoiler("Snake");
			new_entry("Maintain Max Charge", snake_max_charge);
			new_entry("Maintain lvl3 Charge", pstar_lvl3_charge);
			new_entry("Maintain lvl2 Charge", pstar_lvl2_charge);
			new_entry("Maintain lvl1 Charge", pstar_lvl1_charge);
		exit_spoiler();
		new_spoiler("Spur");
			new_entry("Maintain Max Charge", spur_max_charge);
			new_entry("Maintain lvl3 Charge", pstar_lvl3_charge);
			new_entry("Maintain lvl2 Charge", pstar_lvl2_charge);
			new_entry("Maintain lvl1 Charge", pstar_lvl1_charge);
		exit_spoiler();
	exit_spoiler();
	new_spoiler("Miscellaneous");
		new_entry("Faster Movement", faster_movement);
		new_entry("Infinite Air", infinite_air);
		new_entry("Infinite Booster", infinite_booster);
		new_entry("Infinite Jump", infinite_jump);
	exit_spoiler();
	index = new_entry("Masochist Mode", masochist_mode);
	for (i = 2; i <= index; i++)
		set_note(notes[i - 2], i);
}
