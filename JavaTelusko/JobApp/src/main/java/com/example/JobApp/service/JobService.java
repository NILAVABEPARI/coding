package com.example.JobApp.service;

import com.example.JobApp.model.JobPost;
import com.example.JobApp.repo.JobRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

// ! service/JobService.java — the business logic layer

@Service
public class JobService {
    @Autowired
    public JobRepo repo;

    // method to add a jobPost
    public void addJob(JobPost jobPost) {
        repo.addJob(jobPost);
    }

    //method to return all JobPosts
    public List<JobPost> getAllJobs() {
        return repo.getAllJobs();
    }
}

/*
* A thin pass-through layer between the controller and the repo.
* @Service-annotated, it just delegates addJob() and getAllJobs() straight to JobRepo.
* In a real app, this is where you'd add validation, business rules, or logic that doesn't belong in the controller.

 */