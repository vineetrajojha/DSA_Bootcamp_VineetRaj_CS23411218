vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto& prerequisite : prerequisites) {
        int course = prerequisite[0];
        int pre = prerequisite[1];

        graph[pre].push_back(course);
        indegree[course]++;
    } queue<int> q;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> answer;
    
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        answer.push_back(course);

        for (int nextCourse : graph[course]) {
            indegree[nextCourse]--;

            if (indegree[nextCourse] == 0) {
                q.push(nextCourse);
            }
        }
    }
    if (answer.size() != numCourses) {
        return {};
    } return answer;
}