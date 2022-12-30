#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace fm
{

	struct point
	{
		int x, y;
	};

	class app
	{
	private:
		int m_width, m_height;
		std::string m_title;
		sf::RenderWindow* m_window = nullptr;
		sf::Texture	 t1;
		sf::Texture t2;
		sf::Sprite fon;
		sf::Sprite plats;
		point plat[11];
		int h = 250;
	public:
		app()
		{
		}

		~app();

		void setResolution(int width, int height, const std::string& title);

		void setUp();

		void setTextures();

		void run();

		void plts();

		//void loose(point lp);

	};
}