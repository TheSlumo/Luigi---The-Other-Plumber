#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>						//font header files
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>	//primitive header file
#include "Objects.h"
enum Keys{ A, S, D, W };
int res_x = 1280;
int res_y = 720;
int pos_x = 0;

struct person{
	int r = 20;
	int feet = res_y - 55;
	int x = 200;
	int y = feet - (3 * r);
	int j_height = 420;
	int ms = 3;


}player;

int main(void)
{

	bool keys[4] = { false, false, false, false };
	int const FPS = 60;
	bool Gamerunning = true;




	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(res_x, res_y);			//create our display object

	if (!display)										//test display object
		return -1;

	al_init_font_addon();
	al_init_ttf_addon();								//allows for text
	al_init_primitives_addon();
	al_install_keyboard();							// allows to work with keyboard keys.
	al_install_mouse();
	al_hide_mouse_cursor(display);
	timer = al_create_timer(1.0 / FPS);

	event_queue = al_create_event_queue();
	//ALLEGRO_FONT *font18 = al_load_font("arial.ttf", 18, 0);		//sets font18 to arial size 18
	al_register_event_source(event_queue, al_get_keyboard_event_source());	//register keyboard to events.
	al_register_event_source(event_queue, al_get_display_event_source(display)); // Register events from display.
	al_register_event_source(event_queue, al_get_mouse_event_source());//register mouse input to events
	al_register_event_source(event_queue, al_get_timer_event_source(timer));//registers timer 

	al_start_timer(timer);


	while (Gamerunning)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);


		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
			

				break;

			case ALLEGRO_KEY_D:
				keys[D] = true;
				break;
			case ALLEGRO_KEY_A:
				keys[A] = true;
				break;


			}

		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				Gamerunning = false;
				break;
			case ALLEGRO_KEY_L:
				resize(50);

				break;

			case ALLEGRO_KEY_D:
				keys[D] = false;
				break;
			case ALLEGRO_KEY_A:
				keys[A] = false;
				break;

			}

		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			Gamerunning = false;
		}


		else if (ev.type == ALLEGRO_EVENT_TIMER){






			pos_x += keys[D] * player.ms;
			pos_x -= keys[A] * player.ms;

		}

		al_draw_filled_circle(player.x, player.y, player.r, al_map_rgb(0, 128, 0));														//player
		al_draw_filled_rectangle(player.x - player.r, player.y + player.r, player.x + player.r, player.feet, al_map_rgb(0, 128, 0));
		al_draw_filled_rectangle(0, res_y - 50, res_x, res_y, al_map_rgb(139, 69, 19));//Ground		
		//al_draw_filled_rectangle(0, res_y - 40, res_x, res_y - 17, al_map_rgb(0, 0, 200));		

		//_draw_filled_rectangle(550-pos_x, res_y - 350, res_x+(150-pos_x), res_y-270, al_map_rgb(205, 133, 63));
		//_draw_filled_rectangle(1000-pos_x, res_y - 50, res_x -pos_x, res_y - 120, al_map_rgb(10, 200, 50));
		//_draw_filled_rectangle(950 - pos_x, res_y - 120, res_x+50- pos_x, res_y - 170, al_map_rgb(10, 200, 50));











		al_flip_display();
		al_clear_to_color(al_map_rgb(50, 100, 200));

	}
	al_destroy_display(display);
}

void resize(int r1){
	player.r = r1;
	player.y = player.feet - (3 * r1);
	
}
