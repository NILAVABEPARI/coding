package com.example.JobAppRest.service;

import com.example.JobAppRest.model.JobPost;
import com.example.JobAppRest.repo.JobRepo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// ! service/JobService.java — the business logic layer

@Service
public class JobService {

    @Autowired
    public JobRepo repo;

    // method to add a jobPost
    public void addJob(JobPost jobPost) {
        repo.save(jobPost);
    }

    //method to return all JobPosts
    public List<JobPost> getAllJobs() {
        return repo.findAll();
    }

    // method to get a particular jobPost
    public JobPost getJob(int postId) {
        return repo.findById(postId).orElse(new JobPost());
    }

    // method to update a particular jobPost
    public void updateJob(JobPost jobPost) {
        repo.save(jobPost);
    }

    // method to delete a particular jobPost
    public void deleteJob(int postID) {
        repo.deleteById(postID);
    }

    public void load() {
        List<JobPost> jobs = new ArrayList<>(Arrays.asList(
                new JobPost(1, "Java Developer", "Must have good experience in core Java and advanced Java", 2, List.of("Core Java", "J2EE", "Spring Boot", "Hibernate")),
                new JobPost(2, "Frontend Developer", "Experience in building responsive web applications using React", 3, List.of("HTML", "CSS", "JavaScript", "React")),
                new JobPost(3, "Data Scientist", "Strong background in machine learning and data analysis", 4, List.of("Python", "Machine Learning", "Data Analysis")),
                new JobPost(4, "Network Engineer", "Design and implement computer networks for efficient data communication", 5, List.of("Networking", "Cisco", "Routing", "Switching")),
                new JobPost(5, "Mobile App Developer", "Experience in mobile app development for iOS and Android", 3, List.of("iOS Development", "Android Development", "Mobile App"))
        ));

        repo.saveAll(jobs);
    }
}

/*
* A thin pass-through layer between the controller and the repo.
* @Service-annotated, it just delegates addJob() and getAllJobs() straight to JobRepo.
* In a real app, this is where you'd add validation, business rules, or logic that doesn't belong in the controller.

 */