#include "World.hpp"


World::World()
{
    m_clock.restart();
}

void World::cut_update(float x, float y)
{
    float dt = 0.0005f;
    m_clock.restart();

    /*for (std::vector<Point*>::iterator it = m_points.begin() ; it != m_points.end(); ++it)
        (*it)->updateV();*/

	for (int i(4); i--;)
    for (std::vector<Link*>::iterator it = m_links.begin() ; it != m_links.end(); ++it)
    {
        (*it)->update(dt, x, y);
    }

    for (int i(0); i<m_links.size(); ++i)
    {
        if (m_links[i]->isBroken())
            m_links.erase(m_links.begin()+i);
    }

    for (std::vector<Point*>::iterator it = m_points.begin() ; it != m_points.end(); ++it)
        (*it)->updatePos(dt);
}

void World::render(sf::RenderWindow &window)
{
    //std::cout << "ok" << std::endl;
    uint32_t n = static_cast<uint32_t>(m_links.size());
    sf::VertexArray links(sf::Lines, 2*n);
    for (uint32_t i(0); i<n; ++i)
    {
        links[2*i].position = m_links[i]->getPos1();
        links[2*i].color = m_links[i]->getCol1();

        links[2*i+1].position = m_links[i]->getPos2();
        links[2*i+1].color = m_links[i]->getCol2();
    }
    window.draw(links);
}

void World::addCloth(float x_0, float y_0, float num_of_link_x, float num_of_link_y)
{
    float link_length = 11.0f;

    for (int i(0); i<num_of_link_x; ++i)
    {
        for (int j(0); j<num_of_link_y; ++j)
        {
            Point* p = new Point(x_0+link_length*i, y_0+link_length*j, 1000);
            this->addPoint(p);

            if (i > 0)
            {
                Point* px = m_points[static_cast<uint64_t>((i-1)*num_of_link_y)+j];
                this->addLink(new Link(p, px));
            }

            if (j > 0)
            {
                Point* py = m_points[static_cast<uint64_t>(i*num_of_link_y)+j-1];
                this->addLink(new Link(p, py));
            }
            else
                p->fixed = true;
        }
    }
}

