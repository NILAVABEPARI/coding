<%@page language="java" %>

<html>
    <head>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    </body>
        <!-- This will print null becase we are no longer using session -->
        <%-- <h2>Result is : <%= session.getAttribute("result") %></h2> --%>

        <!-- This below line is for adding 2 numbers -->
        <%-- <h2>Result in better way is : ${result} </h2>  --%>

        <!-- This below line is for displaying a new Alien object -->

        <h2> Welcome to hell!!! </h2>
        <p> ${alien1} </p>

        <h2> Welcome to ${course} world!!! </h2>

    </body>
</html>