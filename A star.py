class Vertex:
    def __init__(self, name, heuristic):
        self.name = name
        self.heuristic = heuristic
        self.neighbors = []
        self.visited = 0

    def add_neighbor(self, vertex):
        if vertex not in self.neighbors:
            self.neighbors.append(vertex)
            self.neighbors.sort()

class Graph:
    vertices = {}

    def add_vertex(self, vertex):
        if isinstance(vertex, Vertex) and vertex.name not in self.vertices:
            self.vertices[vertex.name] = vertex
            return True
        return False

    def add_edge(self, u, v, d):
        if u in self.vertices and v in self.vertices:
            for key, value in self.vertices.items():
                if key == u:
                    value.add_neighbor([v, d])
                if key == v:
                    value.add_neighbor([u, d])
            return True
        return False
    
    def priority(self, fx):
        val = []
        for node in fx:
            val.append(node[1] + self.vertices[node[0]].heuristic)
        return self.vertices[fx[val.index(min(val))][0]]

    def cost(self, node, fx):
        for i in fx:
            if node.name == i[0]:
                return i[1]

    def astar(self, start, end):
        ol = []
        cl = []
        gx = 0
        fstr = ''

        ol.append(start)
        while ol != []:
            fx = []
            temp = ol.pop(0)
            temp.visited = 1
            if temp.name == end.name:
                cl.append(end.name)
                break
            cl.append(temp.name)

            for neighbor in temp.neighbors:
                if self.vertices[neighbor[0]].visited == 0:
                    fx.append(neighbor)
            ol.append(self.priority(fx))
            gx += self.cost(ol[0], fx)
        for node in range(len(cl)):
            if node == len(cl) - 1:
                fstr += cl[node]
                break
            fstr += cl[node] + ' --> '
        print('Path to goal state is', fstr, 'with cost of', gx, '.')

if __name__=='__main__':
    graph = Graph()

    #Example 1:
    a = Vertex('A', 14)
    b = Vertex('B', 12)
    c = Vertex('C', 11)
    d = Vertex('D', 6)
    e = Vertex('E', 4)
    f = Vertex('F', 11)
    g = Vertex('G', 0)

    graph.add_vertex(a)
    graph.add_vertex(b)
    graph.add_vertex(c)
    graph.add_vertex(d)
    graph.add_vertex(e)
    graph.add_vertex(f)
    graph.add_vertex(g)

    edges = [['AB', 4], ['AC', 3], ['CD', 7], ['CE', 10], ['DE', 2], ['BE', 12], ['BF', 6], ['FG', 16], ['EG', 5]]
    for edge in edges:
        graph.add_edge(edge[0][:1], edge[0][1:], edge[1])
    
    graph.astar(a, g)
    print('\n')


    #Example 2:
    p = Vertex('P', 7)
    q = Vertex('Q', 6)
    r = Vertex('R', 2)
    s = Vertex('S', 1)
    t = Vertex('T', 0)

    graph.add_vertex(p)
    graph.add_vertex(q)
    graph.add_vertex(r)
    graph.add_vertex(s)
    graph.add_vertex(t)

    edges = [['PQ', 1], ['PR', 4], ['QR', 2], ['QS', 5], ['RS', 2], ['QT', 12], ['ST', 3]]
    for edge in edges:
        graph.add_edge(edge[0][:1], edge[0][1:], edge[1])
    
    graph.astar(p, t)