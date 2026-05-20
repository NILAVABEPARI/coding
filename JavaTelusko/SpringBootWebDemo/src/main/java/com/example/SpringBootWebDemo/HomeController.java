package com.example.SpringBootWebDemo;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class HomeController {

    @RequestMapping("/")
    public String home() {
        System.out.println("home method called");
        return "index";
    }

//    @RequestMapping("add")
//    public String add(HttpServletRequest req, HttpSession session){
//        int num1 = Integer.parseInt(req.getParameter("num1"));
//        int num2 = Integer.parseInt(req.getParameter("num2"));
//        int result =  num1 + num2;
//        System.out.println("result -- "  + result);
//
//        session.setAttribute("result", result);
//
//        return "result.jsp";
//    }

    // better way in spring
//    @RequestMapping("add")
//    public String add(@RequestParam("num1") int n1, @RequestParam("num2")int n2, HttpSession session){
//        int result =  n1 + n2 + 1;
//        System.out.println("result -- "  + result);
//
//        session.setAttribute("result", result);
//
//        return "result.jsp";
//    }

    // optimal way in spring --
//    @RequestMapping("add")
//    public String add(@RequestParam("num1") int n1, @RequestParam("num2") int n2, Model model) {
//        int result = n1 + n2 + 1;
//        System.out.println("result -- " + result);
//
//        model.addAttribute("result", result);
//
//        return "result";
//    }

    @RequestMapping("add")
    public ModelAndView add(@RequestParam("num1") int n1, @RequestParam("num2") int n2, ModelAndView mv) {
        int result = n1 + n2;
        System.out.println("result -- " + result);

        mv.addObject("result", result);
        mv.setViewName("result");

        return mv;
    }

//    @RequestMapping("addAlien")
//    public ModelAndView addAlien(@RequestParam("aid") int aid, @RequestParam("aname") String aname, ModelAndView mv) {
//
//        Alien alien = new Alien();
//        alien.setAid(aid);
//        alien.setAname(aname);
//
//        mv.addObject("alien", alien);
//        mv.setViewName("result");
//
//        return mv;
//    }

    // using ModelAttribute
    // in the below code the model attribute is optional, and it happens behind the scene only if the name alien is same as the variable used in the result.jsp page
    @RequestMapping("addAlien")
    public String addAlien(@ModelAttribute("alien1") Alien alien) {
       return "result";
    }

    // ModelAttribute in method level
    @ModelAttribute("course")
    public String courseName (){
        return "Java";
    }

}
