#include "projecting.h"


ProjectedEdge::ProjectedEdge(Point& pnt1, double i1,
                             Point& pnt2, double i2)
{
    if (pnt1.y < pnt2.y)
        swap(pnt1, pnt2);

    x0 = pnt1.x;
    y0 = static_cast<int>(pnt1.y - pnt2.y);
    z0 = pnt1.z;

    i0 = i1;

    ymax = static_cast<int>(pnt1.y);

    if (y0)
    {
        dx = (pnt2.x - pnt1.x) / y0;
        dz = (pnt2.z - pnt1.z) / y0;

        di = (i2 - i1) / y0;
    }
    else
    {
        dx = 0;
        dz = 0;

        di = 0;
    }

    reset();
}

ProjectedEdge::ProjectedEdge(const ProjectedEdge& other)
{
    x0 = other.x0;
    y0 = other.y0;
    z0 = other.z0;
    i0 = other.i0;

    x = other.x;
    y = other.y;
    z = other.z;
    i = other.i;

    dx = other.dx;
    dz = other.dz;
    di = other.di;

    ymax = other.ymax;
}

ProjectedEdge::~ProjectedEdge() {}

void ProjectedEdge::reset()
{
    x = x0;
    y = y0;
    z = z0;
    i = i0;
}

bool ProjectedEdge::step()
{
    x += dx;
    z += dz;
    y -= 1;
    i += di;

    return y <= 0;
}

bool ProjectedEdge::is_horizontal() const
{
    return y0 == 0;
}


ProjectedSide::ProjectedSide() {}

ProjectedSide::ProjectedSide(ProjectedSide&& other) :
    edges(other.edges), active_edges(other.active_edges), waiting_edges(other.waiting_edges)
{
    y_temp = other.y_temp;
}

ProjectedSide::~ProjectedSide()
{
    edges.clear();
    active_edges.clear();
    waiting_edges.clear();
}

void ProjectedSide::init()
{
    size_t i = 0;

    y_temp = edges[0].ymax;

    while (edges[i].ymax == y_temp && i < edges.size())
    {
        active_edges.push_back(edges[i]);
        i++;
        cout << i << " " << edges.size() << endl;
    }

    for (; i < edges.size(); i++)
    {
        waiting_edges.push_back(edges[i]);
        cout << "+++" << endl;
    }
}

bool ProjectedSide::step()
{
    y_temp -= 1;

    for (auto i = active_edges.begin(); i < active_edges.end();)
    {
        if (i->step())
            active_edges.erase(i);
        else
            i++;
    }

    auto i = waiting_edges.begin();
    while (i < waiting_edges.end() && y_temp == i->ymax)
    {
        active_edges.push_back(*i);
        waiting_edges.erase(i);
        i++;
    }

    return active_edges.size() == 0;
}

void ProjectedSide::add_edge(const ProjectedEdge &edge)
{
    if (edge.is_horizontal())
        return;

    edges.push_back(edge);

    for (size_t i = edges.size()-1; i > 0; i--)
    {
        if (edges[i - 1].ymax < edges[i].ymax)
            swap(edges[i - 1], edges[i]);
        else if (edges[i - 1].ymax == edges[i].ymax)
        {
            if (edges[i - 1].x > edges[i].x)
                swap(edges[i - 1], edges[i]);
            else if (edges[i - 1].x == edges[i].x &&
                     edges[i - 1].dx > edges[i].dx)
                swap(edges[i - 1], edges[i]);
            else
                break;
        }
        else
            break;
    }
}
