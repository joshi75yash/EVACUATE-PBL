# EVACUATE-PBL
Intelligent Emergency Route & Crowd Management System

EVACUATE tackles a simple but tricky problem: a safe route right now might not stay safe. A corridor can get blocked, an exit can suddenly close, or too many people can pile onto the same path — and the system needs to adapt instead of handing out one fixed route and hoping for the best.

We model the evacuation zone as a graph, using BFS, DFS, and Dijkstra's algorithm to find and re-check routes as conditions shift. Queues and Priority Queues handle the movement of people, tracking who's going where and in what order.

Users can simulate real disruptions too — adding hazards or manually blocking paths — and the system responds by searching for another viable route instead of just failing. A graphical interface ties it together, showing the map, people, routes, and hazards at a glance.

For testing, we're going past the happy path: blocked exits, overcrowded corridors, even sections that get fully cut off from the rest of the graph, to see whether the system holds up under real failure conditions rather than just ideal ones.
