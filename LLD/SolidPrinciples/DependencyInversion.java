interface RecommendationStrategy {
    void getRecommendations();
}

class RecentlyAdded implements RecommendationStrategy {
    @Override
    public void getRecommendations() {
        System.out.println("Recently Added movies...");
    }
}

class GenreBased implements RecommendationStrategy {
    @Override
    public void getRecommendations() {
        System.out.println("Genre Based movies...");
    }
}

class TrendingNow implements RecommendationStrategy {
    @Override
    public void getRecommendations() {
        System.out.println("Trending Now movies...");
    }
}

class RecommendationAlgorithm {
    private RecommendationStrategy recommendationStrategy;

    public RecommendationAlgorithm(RecommendationStrategy recommendationStrategy) {
        this.recommendationStrategy = recommendationStrategy;
    }

    public void recommend() {
        recommendationStrategy.getRecommendations();
    }
}

public class DependencyInversion {
    public static void main(String[] args) {
        RecommendationAlgorithm genreBasedAlgo = new RecommendationAlgorithm(new GenreBased());
        RecommendationAlgorithm TrendingBasedAlgo = new RecommendationAlgorithm(new TrendingNow());
        RecommendationAlgorithm RecentAlgo = new RecommendationAlgorithm(new RecentlyAdded());

        genreBasedAlgo.recommend();
        TrendingBasedAlgo.recommend();
        RecentAlgo.recommend();
    }
}
