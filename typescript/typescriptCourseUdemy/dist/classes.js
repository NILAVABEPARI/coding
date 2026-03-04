"use strict";
class Department {
    constructor(id, name) {
        this.id = id;
        this.name = name;
        this.employees = [];
    }
    describe() {
        console.log(`Department : (${this.id}) + ${this.name}`);
    }
    addEmployee(employee) {
        this.employees.push(employee);
    }
    printEmployeeInformation() {
        console.log(this.employees.length);
        console.log(this.employees);
    }
}
;
class ITDepartment extends Department {
    constructor(id, admins) {
        super(id, "IT Department");
        this.admins = admins;
    }
}
class AccountingDepartment extends Department {
    constructor(id, reports) {
        super(id, "Accounting Department");
        this.reports = reports;
    }
    addReports(report) {
        this.reports.push(report);
    }
    printReport() {
        console.log(this.reports);
    }
}
const it = new ITDepartment("d1", ["nilava"]);
it.addEmployee("nilava");
it.addEmployee("tandrima");
it.describe();
it.printEmployeeInformation();
console.log(it);
const accounting = new AccountingDepartment('d2', []);
accounting.addReports("something went wrong ....");
accounting.printReport();
//# sourceMappingURL=classes.js.map