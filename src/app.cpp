#include <app.hpp>
#include <SFML/Graphics.hpp>
//#include <time.h>
#include <doodle.hpp>

namespace fm
{
	app::~app()
	{
		if (m_window != nullptr)
		{
			delete m_window;
		}

	}

	void app::setResolution(int width, int height, const std::string& title)
	{
		m_width = width;
		m_height = height;
		m_title = title;
	}

	void app::setTextures()
	{
		t1.loadFromFile("images/background.png");
		t2.loadFromFile("images/platform.png");
		fon.setTexture(t1);
		plats.setTexture(t2);
	}

	void app::setUp()
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_title);
		m_window->setFramerateLimit(60);
	}

	void app::plts()
	{
		for (int i = 0; i < 10; i++)
		{
			plat[i].x = rand() % 400;
			plat[i].y = rand() % 533;
		}
	}

	void app::run()
	{
		fm::doodle* doodl;
		doodl = new fm::doodle({0, 0}, {100, 0});
		doodl->setDoodle();


		while (m_window->isOpen())
		{

			sf::Event event;
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					m_window->close();
				}
			}

			point np = doodl->doodlejump();
			vec nd = doodl->getd();

			if (np.y < h) // смена координат платформ, после выхода за экран платформ
			{
				for (int i = 0; i < 10; i++)
				{
					np.y = h;
					doodl->setp(np);
					plat[i].y = plat[i].y - nd.y;
					if (plat[i].y > 533)
					{
						plat[i].y = 0;
						plat[i].x = rand() % 400;
					}
				}
			}

			for (int i = 0; i < 10; i++)
			{
				if ((np.x + 50 > plat[i].x) && (np.x < plat[i].x + 68)
					&& (np.y + 70 > plat[i].y) && (np.y + 70 < plat[i].y + 14) && (nd.y > 0))
				{
					nd.y = -10;
					doodl->setd(nd);
				}
			}

			doodl->setPos();

			m_window->clear(); 
			m_window->draw(fon);
			m_window->draw(*doodl->getDoodle());

			for (int i = 0; i < 10; i++)
			{
				plats.setPosition(plat[i].x, plat[i].y);
				m_window->draw(plats);
			}

			m_window->display(); 
			if (doodl->getp().y > 500)
			{
				break;
			}
		}
	}
}