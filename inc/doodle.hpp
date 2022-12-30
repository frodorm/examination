#pragma once
#include <SFML/Graphics.hpp>
#include <app.hpp>

namespace fm
{
	struct vec
	{
		float x, y;
	};

	class doodle
	{
	private:
		sf::Texture* dod = nullptr;
		sf::Sprite* doo = nullptr;
		vec d;
		point p;
	public:
		doodle(vec dxy, point pxy)
		{
			d = dxy;
			p = pxy;
		}

		void setDoodle();

		sf::Sprite* getDoodle();

		point doodlejump();
		
		void setd(vec nd);

		void setp(point np);

		vec getd();

		void setPos();

		point getp();

		~doodle();
	};
}