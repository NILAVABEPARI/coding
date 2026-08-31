package com.example.JobAppRest;

import com.example.JobAppRest.model.JobPost;
import com.example.JobAppRest.service.JobService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

// * @RestController is actually shorthand for @Controller + @ResponseBody applied to every method in the class automatically.
@RestController
@CrossOrigin("http://localhost:3000")
public class JobRestController {

    @Autowired
    private JobService service;

    // ! @ResponseBody -- this is common for any route
    // ! produces = {"application/json"} -- makes sure that only json format is returned and returns error if xml is requested
    @GetMapping(path = "jobPosts", produces = {"application/json"})
    public List<JobPost> getAllJobs() {
        return service.getAllJobs();
    }

    // ! in this way we can get variables from url path
    @GetMapping("jobPost/{postID}")
    public JobPost getJob(@PathVariable("postID") int postID) {
        return service.getJob(postID);
    }

    @PostMapping("jobPost")
    public JobPost addJob(@RequestBody JobPost jobPost) {
        service.addJob(jobPost);
        return service.getJob(jobPost.getPostId());
    }

    @PutMapping("jobPost")
    public JobPost updateJob(@RequestBody JobPost jobPost) {
        service.updateJob(jobPost);
        return service.getJob(jobPost.getPostId());
    }

    @DeleteMapping("jobPost/{postID}")
    public String deleteJob(@PathVariable("postID") int postID) {
        service.deleteJob(postID);
        return "Deleted Job";
    }

    @GetMapping("load")
    public String loadData() {
        service.load();
        return "success";
    }
}

/*
 * @Controller → returns view names by default (your JSP-based JobController)
 * @Controller + @ResponseBody on a method → that one method returns raw data instead of a view
 * @RestController → every method in the class returns raw data by default (this file)
 */