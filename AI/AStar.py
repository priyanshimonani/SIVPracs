graph = {
    'S':[('A',3),('B',2)],
    'A':[('C',2),('D',5)],
    'B':[('D',1)],
    'C':[('G',5)],
    'D':[('G',3)],
    'G':[]
}

h = {'S':7,'A':6,'B':4,'C':2,'D':1,'G':0}

def astar(start, goal):

    open = [(start,0)]
    closed = set()

    parent = {start:None}
    g = {start:0}

    while open:

        node,cost = min(
            open,
            key=lambda x:x[1]+h[x[0]]
        )

        open.remove((node,cost))

        if node == goal:

            path = []

            while node:
                path.append(node)
                node = parent[node]

            print("Path :"," -> ".join(path[::-1]))
            print("Cost :",g[goal])
            return

        closed.add(node)

        for nxt,w in graph[node]:

            newg = g[node] + w

            if nxt not in g or newg < g[nxt]:

                g[nxt] = newg
                parent[nxt] = node

                # Reopen node if better path found
                if nxt in closed:
                    closed.remove(nxt)

                open.append((nxt,newg))

astar('S','G')