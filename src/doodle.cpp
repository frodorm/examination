#include <SFML/Graphics.hpp>
#include <app.hpp>
#include <doodle.hpp>

namespace fm
{
	void doodle::setDoodle()
	{
		dod = new sf::Texture;
		doo = new sf::Sprite;
		dod->loadFromFile("images/doodle.png");
		doo->setTexture(*dod);
	}

	sf::Sprite* doodle::getDoodle()
	{
		return doo;
	}

	point doodle::doodlejump()
	{
		d.y += 0.2;
		p.y += d.y;
		if (p.y > 500)
		{
			d.y = -10;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			p.x += 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			p.x -= 3;
		}

		return p;
	}

	void doodle::setd(vec nd)
	{
		d = nd;
	}

	void doodle::setp(point np)
	{
		p = np;
	}

	vec doodle::getd()
	{
		return d;
	}

	void doodle::setPos()
	{
		doo->setPosition(p.x, p.y);
	}

	point doodle::getp()
	{
		return p;
	}

	doodle::~doodle()
	{
		if (dod != nullptr)
		{
			delete dod;
		}

		if (doo != nullptr)
		{
			delete doo;
		}
	}
}