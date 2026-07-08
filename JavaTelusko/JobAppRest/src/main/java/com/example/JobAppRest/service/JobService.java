package com.example.JobAppRest.service;

import com.example.JobAppRest.model.JobPost;
import com.example.JobAppRest.repo.JobRepo;
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

    // method to get a particular jobPost
    public JobPost getJob(int postId) {
        return repo.getJob(postId);
    }

    // method to update a particular jobPost
    public void updateJob(JobPost jobPost) {
        repo.updateJob(jobPost);
    }

    // method to delete a particular jobPost
    public void deleteJob(int postID) {
        repo.deleteJob(postID);
    }
}

/*
* A thin pass-through layer between the controller and the repo.
* @Service-annotated, it just delegates addJob() and getAllJobs() straight to JobRepo.
* In a real app, this is where you'd add validation, business rules, or logic that doesn't belong in the controller.

 */