/*
	Include NotUnity.h
	Inherit a class from NotUnityApp. Override method OnUpdate in it
	Feed the name of your class to START_NOTUNITY_GAME macro.
*/

#include "NotUnity.h"
#include "Unit.h"
#include <cstdlib>

class Fall22Game : public NotUnity::NotUnityApp
{
public:
	Fall22Game()
	{
		NotUnity::NotUnityWindow::GetWindow()->SetKeyPressedCallback(
			[this](const NotUnity::KeyPressedEvent& event) {OnKeyPress(event); });

		NotUnity::NotUnityWindow::GetWindow()->SetKeyReleasedCallback(
			[this](const NotUnity::KeyReleasedEvent& event) {OnKeyRelease(event); });
	}

	void OnUpdate() override
	{
		// Keyboard Inputs
		NotUnity::NotUnityWindow::GetWindow()->SetKeyPressedCallback([&](const NotUnity::KeyPressedEvent& event)
		{
				if (event.GetKeyCode() == NOTUNITY_KEY_LEFT) x -= 10;
				else if (event.GetKeyCode() == NOTUNITY_KEY_RIGHT) x += 10;
				else if (event.GetKeyCode() == NOTUNITY_KEY_UP) y += 10;
				else if (event.GetKeyCode() == NOTUNITY_KEY_DOWN) y -= 10;
		});

		// Setting collected powerup to false to draw the powerup
		collected_powerup = false;

		// Vectors for triangulating player position
		vec_x = x - x_enemy_1;
		vec_y = y - y_enemy_1;

		// Hypotenuse for normalising vectors
		hyp = sqrt(vec_x * vec_x + vec_y * vec_y);
		
		vec_x /= hyp;
		vec_y /= hyp;

		// Updating Player character coordinates
		m_Character.SetCoord(x, y, 1);
		m_Character.Draw();

		// End the game if the player makes contact with the enemy and is out of hitpoints
		if (m_Character.OverlapsWith(m_Enemy1))
		{
			if (m_Character.GetHP() == 1)
			{
				exit(0);
			}
			else if (m_Character.GetHP() > 1)
			{
				m_Character.ChangeHP(-1);
				x_enemy_1 -= 150;
				y_enemy_1 -= 150;
			}
		}

		// Making the enemy chase the player character on a direct path
		m_Enemy1.SetCoord(x_enemy_1 += vec_x * 1.1, y_enemy_1 += vec_y * 1.1, 1);
		m_Enemy1.Draw();

		// Collect the powerup if player character hits it
		if (m_Character.OverlapsWith(m_Powerup))
		{
			collected_powerup = true;
		}

		// Generate new powerup if player character collects previous one,
		// Also do a check on the score to see if an item needs to be generated
		if (collected_powerup == true)
		{
			score += 1;
			x_power = 1 + (rand() % 800);
			y_power = 1 + (rand() % 600);

			// If score is not 0 and score is divisable by 7, then set item coords and set 
			// collected item bool to false
			if (score != 0 && score % 7 == 0)
			{
				x_item = 1 + (rand() % 800);
				y_item = 1 + (rand() % 600);
				m_Item.SetCoord(x_item, y_item, 1);
				collected_item = false;
			}
		}

		// If the item bool is false, draw the item
		if (collected_item == false)
		{
			m_Item.Draw();
		}

		// If the player tags the item, then add a hitpoint
		if (m_Character.OverlapsWith(m_Item) && collected_item == false)
		{
			m_Character.ChangeHP(+1);
			collected_item = true;
		}

		// If score is 10 or greater, add a difficulty spike in the form of a 2nd enemy
		// that runs at the player in greater speed
		if (score >= 10)
		{
			// Vectors for triangulating player position
			vec_x = x - x_enemy_2;
			vec_y = y - y_enemy_2;

			// Hypotenuse to normalise the vectors
			hyp = sqrt(vec_x * vec_x + vec_y * vec_y);

			vec_x /= hyp;
			vec_y /= hyp;

			// End the game if the player makes contact with the enemy with not enough hitpoints
			if (m_Character.OverlapsWith(m_Enemy2))
			{
				if (m_Character.GetHP() == 1)
				{
					exit(0);
				}
				else if (m_Character.GetHP() > 1)
				{
					m_Character.ChangeHP(-1);
					x_enemy_2 -= 200;
					y_enemy_1 -= 200;
				}
			}

			// Making the enemy chase the player character on a direct path
			m_Enemy2.SetCoord(x_enemy_2 += vec_x * 2.0, y_enemy_2 += vec_y * 2.0, 1);
			m_Enemy2.Draw();
		}

		// Draw the powerup
		m_Powerup.SetCoord(x_power, y_power, 1);
		m_Powerup.Draw();
	}

private:
	NotUnity::Unit m_Character{ "Assets/Textures/character.png", 1 };
	NotUnity::Unit m_Enemy1{ "Assets/Textures/enemy1.png", 1 };
	NotUnity::Unit m_Enemy2{ "Assets/Textures/enemy2.png", 1 };
	NotUnity::Unit m_Powerup{ "Assets/Textures/powerup.png", 1 };
	NotUnity::Unit m_Item{ "Assets/Textures/item.png", 1 };
	int m_Speed{ 1 };
	int m_Frames{ 0 };
	int x{ 400 };
	int y{ 400 };
	float x_enemy_1{ 100 };
	float y_enemy_1{ 100 };
	float x_enemy_2{ 600 };
	float y_enemy_2{ 600 };
	int x_power{ 0 };
	int y_power{ 0 };
	int x_item{ 0 };
	int y_item{ 0 };
	float vec_x{ 0 };
	float vec_y{ 0 };
	float hyp{ 0 };
	int score{ 0 };
	bool collected_powerup{ false };
	bool collected_item{ true };

	enum class CharState {
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_UP,
		MOVE_DOWN,
		STILL
	} m_State{ CharState::STILL };

	void OnKeyPress(const NotUnity::KeyPressedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case NOTUNITY_KEY_LEFT:
			m_State = CharState::MOVE_LEFT;
			break;
		case NOTUNITY_KEY_RIGHT:
			m_State = CharState::MOVE_RIGHT;
			break;
		case NOTUNITY_KEY_UP:
			m_State = CharState::MOVE_UP;
			break;
		case NOTUNITY_KEY_DOWN:
			m_State = CharState::MOVE_DOWN;
			break;
		}
	}

	void OnKeyRelease(const NotUnity::KeyReleasedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case NOTUNITY_KEY_LEFT:
			if (m_State == CharState::MOVE_LEFT)
				m_State = CharState::STILL;
			break;
		case NOTUNITY_KEY_RIGHT:
			if (m_State == CharState::MOVE_RIGHT)
				m_State = CharState::STILL;
			break;
		case NOTUNITY_KEY_UP:
			if (m_State == CharState::MOVE_UP)
				m_State = CharState::STILL;
			break;
		case NOTUNITY_KEY_DOWN:
			if (m_State == CharState::MOVE_DOWN)
				m_State = CharState::STILL;
			break;
		}
	}

};

START_NOTUNITY_GAME(Fall22Game)