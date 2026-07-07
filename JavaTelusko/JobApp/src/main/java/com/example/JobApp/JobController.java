package com.example.JobApp;

import com.example.JobApp.model.JobPost;
import com.example.JobApp.service.JobService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

// ! JobController.java — the request handler

@Controller
public class JobController {

    @Autowired
    private JobService service;

    @RequestMapping({"/", "home"})
    public String home(){
        return "home";
    }

    @GetMapping("addjob")
    public String addJob(){
        return "addjob";
    }

    @PostMapping("handleForm")
    public String handleForm(JobPost jobPost, Model model){
        service.addJob(jobPost);
        model.addAttribute("jobPost", jobPost);
        return "success";
    }

    @GetMapping("viewalljobs")
    public String viewJobs(Model model){
        List<JobPost> jobs = service.getAllJobs();
        model.addAttribute("jobPosts", jobs);
        return "viewalljobs";
    }
}

/*
* / or /home → returns "home" → resolves to home.jsp (landing page with two buttons)
* /addjob (GET) → returns "addjob" → shows the job-posting form
* /handleForm (POST) → takes form data, binds it into a JobPost object automatically (Spring's data binding matches form field name attributes to JobPost fields), saves it via the service, returns "success"
* /viewalljobs (GET) → fetches all jobs from the service, puts them in the Model under key "jobPosts", returns "viewalljobs" → JSP loops over that list
 */