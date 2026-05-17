package org.example;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class App
{
    public static void main( String[] args )
    {
        // instead of writing Alien obj = new Alien(); spring is creating the object for me
        // the below code starts a spring container
        // all the objects mentioned in the spring.xml file will be created in this line
        ApplicationContext context = new ClassPathXmlApplicationContext("spring.xml");

        // the below line tells spring -- Give me the object whose id is alien
        // we are type casting because by default .getBean returns an object type

        // by default, we will get the reference of the same object because the scope is singleton
        Alien obj = (Alien) context.getBean("alien");

        // we did not use the setter directly to set the age
        System.out.println(obj.getAge());
        obj.code();

        // Alien obj2 = (Alien) context.getBean("alien");
        // obj2.code();

    }
}
