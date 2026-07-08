package com.example.JobAppRest;

import com.example.JobAppRest.model.JobPost;
import com.example.JobAppRest.service.JobService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@CrossOrigin("http://localhost:3000")
public class JobRestController {

    @Autowired
    private JobService service;

    @GetMapping(path = "jobPosts", produces = {"application/json"})
//    @ResponseBody
    public List<JobPost> getAllJobs(){
        return service.getAllJobs();
    }

    @GetMapping("jobPost/{postID}")
    public JobPost getJob(@PathVariable("postID") int postID){
        return service.getJob(postID);
    }

    @PostMapping("jobPost")
    public JobPost addJob(@RequestBody JobPost jobPost){
        service.addJob(jobPost);
        return service.getJob(jobPost.getPostId());
    }

    @PutMapping("jobPost")
    public JobPost updateJob(@RequestBody JobPost jobPost){
        service.updateJob(jobPost);
        return service.getJob(jobPost.getPostId());
    }

    @DeleteMapping("jobPost/{postID}")
    public String deleteJob(@PathVariable("postID") int postID){
        service.deleteJob(postID);
        return "Deleted Job";
    }
}
