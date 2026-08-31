package com.example.JobAppRest.model;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.stereotype.Component;

import java.util.List;

// ! model/JobPost.java — the data shape

/*
* @Data generates getters, setters, toString(), equals(), and hashCode() for you behind the scenes at compile time — the actual bytecode has all that boilerplate, you just don't have to type or maintain it.
Common Lombok annotations you'll run into:

@Getter / @Setter — generates just getters/setters
@Data — bundles getters, setters, toString, equals, hashCode
@NoArgsConstructor / @AllArgsConstructor — generates constructors
@Builder — gives you a fluent builder pattern for object creation
@Slf4j — auto-generates a logger field, so you can just write log.info(...) without declaring it

 */

@Data
@NoArgsConstructor
@AllArgsConstructor
@Component
@Entity
public class JobPost {
    @Id
    private int postId;
    private String postProfile;
    private String postDesc;
    private Integer reqExperience;
    private List<String> postTechStack;
}

/*
 * Lombok -- Lombok is a Java library that generates boilerplate code for you automatically at compile time, using annotations — so you write less code by hand.
 A plain POJO representing one job posting: postId, postProfile, postDesc, reqExperience, postTechStack (a List<String>).
 Also marked @Component so Spring manages it as a bean.
 */
