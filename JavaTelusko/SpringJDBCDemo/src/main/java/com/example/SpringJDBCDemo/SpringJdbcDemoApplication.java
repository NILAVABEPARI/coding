package com.example.SpringJDBCDemo;

import com.example.SpringJDBCDemo.model.Student;
import com.example.SpringJDBCDemo.service.StudentService;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

import java.util.List;

@SpringBootApplication
public class SpringJdbcDemoApplication {

	public static void main(String[] args) {
		ApplicationContext context = SpringApplication.run(SpringJdbcDemoApplication.class, args);

        Student s = context.getBean(Student.class);
        s.setMarks(78);
        s.setName("Nilava");
        s.setRollNo(104);


        StudentService service = context.getBean(StudentService.class);
        service.addStudent(s);

        List<Student> students = service.getStudents();
        System.out.println(students);
	}

}
