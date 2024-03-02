// cpp-blind-75/58_course-schedule.cpp
/**
 * Date  : 09-Aug-2023
 * Repo: https://github.com/ankitsamaddar/
 *
 * Problem   :  Course Schedule
 * Difficulty:  🟡Medium
 *
 * Leetcode 0207 :  https://leetcode.com/problems/course-schedule
 * Lintcode 0615 :  https://www.lintcode.com/problem/615
 */

class Solution {
  public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // initialize empty list for each course
    for (int i = 0; i < numCourses; i++) {
      preMap[i] = {};
    }

    // hash the prerequisites to the map
    for (vector<int>& pre : prerequisites) {
      preMap[pre[0]] .push_back(pre[1]);
    }

    // check if cycle is detected for each course
    for (int i = 0; i < numCourses; i++) {
      if (!dfs(i)) return false;
    }

    return true;
  }

  private:
  unordered_map<int, vector<int>> preMap;

  unordered_set<int> visitedSet; // keep track of visited node in DFS traversal

  bool dfs(int crs) {
    // if already visited
    if (visitedSet.count(crs)) {
      return false;
    }

    // add course to list
    visitedSet.insert(crs);

    // for each pre-requisite course of the current course
    // do DFS traversal
    for (int pre : preMap[crs]) {
      if (!dfs(pre)) return false;
    }

    // Reset current course as it is already checked
    visitedSet.erase(crs);
    preMap[crs] = {};

    // true as current course has no cycles
    return true;
  }
};
