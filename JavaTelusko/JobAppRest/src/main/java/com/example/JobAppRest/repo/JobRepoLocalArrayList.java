package com.example.JobAppRest.repo;

import com.example.JobAppRest.model.JobPost;
import org.springframework.stereotype.Repository;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// ! repo/JobRepo.java — the data layer

@Repository
public class JobRepoLocalArrayList {
    // ArrayList to store JobPost objects
    List<JobPost> jobs = new ArrayList<>(Arrays.asList(
            new JobPost(1, "Java Developer", "Must have good experience in core Java and advanced Java", 2, List.of("Core Java", "J2EE", "Spring Boot", "Hibernate")),
            new JobPost(2, "Frontend Developer", "Experience in building responsive web applications using React", 3, List.of("HTML", "CSS", "JavaScript", "React")),
            new JobPost(3, "Data Scientist", "Strong background in machine learning and data analysis", 4, List.of("Python", "Machine Learning", "Data Analysis")),
            new JobPost(4, "Network Engineer", "Design and implement computer networks for efficient data communication", 5, List.of("Networking", "Cisco", "Routing", "Switching")),
            new JobPost(5, "Mobile App Developer", "Experience in mobile app development for iOS and Android", 3, List.of("iOS Development", "Android Development", "Mobile App"))
    ));

    // method to return all JobPosts
    public List<JobPost> getAllJobs() {
        return jobs;
    }

    // method to save a job post object into arrayList
    public void addJob(JobPost job) {
        jobs.add(job);
        System.out.println(jobs);
    }

    // method to get a particular job object from arrayList
    public JobPost getJob(int postId) {
        for (JobPost job : jobs) {
            if (job.getPostId() == postId) {
                return job;
            }
        }
        return null;
    }

    // method to update a particular job object from arrayList
    public void updateJob(JobPost jobPost) {
        for(JobPost job : jobs){
            if(job.getPostId() == jobPost.getPostId()){
                job.setPostProfile(jobPost.getPostProfile());
                job.setPostDesc(jobPost.getPostDesc());
                job.setReqExperience(jobPost.getReqExperience());
                job.setPostTechStack(jobPost.getPostTechStack());
            }
        }
    }

    // method to delete a particular job object from arrayList
    public void deleteJob(int postID) {
//        for (JobPost job : jobs) {
//            if (job.getPostId() == postID) {
//                jobs.remove(job);
//            }
//        }
        // * a better way to write the remove functionality
        jobs.removeIf(job -> job.getPostId() == postID);
    }
}

/*
 * This is your "database" — except there's no real database.
 * It's an in-memory ArrayList<JobPost> preloaded with 5 hardcoded job posts.
 * @Repository marks it as Spring-managed.
 * Two methods: getAllJobs() returns the list, addJob() appends to it.
 * Since it's just an ArrayList in memory, any job you add disappears when the app restarts.
 */