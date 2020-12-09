class Edge(object):
    x1, y1 = 0, 0
    x2, y2 = 0, 0

    def __init__(self, point_1, point_2):
        self.x1, self.y1 = point_1.x, point_1.y
        self.x2, self.y2 = point_2.x, point_2.y
        self.x = self.x2 - self.x1
        self.y = self.y2 - self.y1

class Point(object):
    x, y = 0, 0

    def __init__(self, x, y):
        self.x = x
        self.y = y

def add_edge(edges_arr, point_1, point_2):
    new_edge = Edge(point_1, point_2)
    edges_arr.append(new_edge)

    '''for i in range(len(edges_arr)):
        print(edges_arr[i].x1, edges_arr[i].y1, edges_arr[i].x2, edges_arr[i].y2)'''

class Vector(object):
    x, y = 0, 0

    def __init__(self, point_1, point_2):
        self.x = point_2.x - point_1.x
        self.y = point_2.y - point_1.y