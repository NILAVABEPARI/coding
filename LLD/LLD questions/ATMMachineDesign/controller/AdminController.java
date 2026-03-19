package controller;

import domain.CashDrawer;
import domain.Denomination;
import java.util.Map;
import service.AdminService;

public class AdminController {
    private final AdminService adminService;

    public AdminController(AdminService adminService) {
        this.adminService = adminService;
    }

    public boolean loginAdmin(String adminId, String pin) {
        return adminService.loginAdmin(adminId, pin);
    }

    public void refillCash(String atmId, Map<Denomination, Integer> notes) {
        adminService.refillCash(atmId, notes);
    }

    public CashDrawer auditCash(String atmId) {
        return adminService.auditCash(atmId);
    }
}
