#include "projecting.h"


ProjectedEdge::ProjectedEdge(Point& pnt1, Point& pnt2)
{
    if (pnt1.y < pnt2.y)
        swap(pnt1, pnt2);

    x0 = pnt1.x;
    y0 = static_cast<int>(pnt1.y - pnt2.y);
    z0 = pnt1.z;

    ymax = static_cast<int>(pnt1.y);

    if (y0)
    {
        dx = (pnt2.x - pnt1.x) / y0;
        dz = (pnt2.z - pnt1.z) / y0;
    }
    else
    {
        dx = 0;
        dz = 0;
    }

    reset();
}

ProjectedEdge::ProjectedEdge(const ProjectedEdge& other)
{
    x0 = other.x0;
    y0 = other.y0;
    z0 = other.z0;

    x = other.x;
    y = other.y;
    z = other.z;

    dx = other.dx;
    dz = other.dz;

    ymax = other.ymax;
}

ProjectedEdge::~ProjectedEdge() {}

void ProjectedEdge::reset()
{
    x = x0;
    y = y0;
    z = z0;
}

bool ProjectedEdge::is_horizontal() const
{
    return y0 == 0;
}


ProjectedSide::ProjectedSide() {}

ProjectedSide::ProjectedSide(const ProjectedSide& other) :
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

    while (edges[i].ymax == y_temp)
    {
        active_edges.push_back(edges[i]);
        i++;
    }

    for (; i < edges.size(); i++)
        waiting_edges.push_back(edges[i]);
}

void ProjectedSide::add_edge(const ProjectedEdge &edge)
{
    if (edge.is_horizontal())
        return;

    edges.push_back(edge);

    //
}
