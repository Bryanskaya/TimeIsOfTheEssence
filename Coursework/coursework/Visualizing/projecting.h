#ifndef PROJECTING_H
#define PROJECTING_H

#include "Primitives/Model/model.h"


class ProjectedEdge
{
public:
    double x0, x;
    double y0, y;
    double z0, z;

    double dx;
    double dz;

    int ymax;

    ProjectedEdge(Point& pnt1, Point& pnt2);
    ProjectedEdge(const ProjectedEdge& other);

    ~ProjectedEdge();

    void reset();
    bool is_horizontal() const;
};

class ProjectedSide
{
public:
    vector<ProjectedEdge> edges;
    vector<ProjectedEdge> active_edges;
    vector<ProjectedEdge> waiting_edges;
    int y_temp;


    ProjectedSide();
    ProjectedSide(const ProjectedSide& other);

    ~ProjectedSide();

    void init();
    void add_edge(const ProjectedEdge& edge);
};

#endif // PROJECTING_H
