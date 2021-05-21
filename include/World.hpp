#ifndef WORLD_H_INCLUDED
#define WORLD_H_INCLUDED

#include <vector>
#include "Link.hpp"


class World
{
public:
    World();

    void addPoint(Point* point) {m_points.push_back(point);};
    void addLink(Link* link) {m_links.push_back(link);};

    void addCloth(float x_0, float y_0, float num_of_link_x, float num_of_link_y);

    void cut_update(float x, float y);
    void render(sf::RenderWindow &window);

    float get_clock(){return m_clock.getElapsedTime().asSeconds();};
private:
    sf::Clock m_clock;
    std::vector<Point*> m_points;
    std::vector<Link*> m_links;

};

#endif // WORLD_H_INCLUDED
