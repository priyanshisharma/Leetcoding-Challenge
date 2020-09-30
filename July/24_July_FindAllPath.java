class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> rst = new LinkedList<>();
        List<Integer> path = new LinkedList<>();
        path.add(0);
        dfs(graph, 0, path, rst);
        return rst;
    }

    private void dfs(int[][] graph, int index, List<Integer> path, List<List<Integer>> rst) {
        if (index == graph.length - 1) {
            rst.add(new LinkedList<>(path));
            return;
        }

        for (int neigh : graph[index]) {
            path.add(neigh);
            dfs(graph, neigh, path, rst);
            // Backtracking
            path.remove(path.size() - 1);
        }
    }
}
