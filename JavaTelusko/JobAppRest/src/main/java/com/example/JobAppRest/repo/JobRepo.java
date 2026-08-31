package com.example.JobAppRest.repo;

import com.example.JobAppRest.model.JobPost;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

// ! repo/JobRepo.java — the data layer

@Repository
public interface JobRepo extends JpaRepository<JobPost,Integer> {

}

/*
 * This is your "database" — except there's no real database.
 * It's an in-memory ArrayList<JobPost> preloaded with 5 hardcoded job posts.
 * @Repository marks it as Spring-managed.
 * Two methods: getAllJobs() returns the list, addJob() appends to it.
 * Since it's just an ArrayList in memory, any job you add disappears when the app restarts.
 */