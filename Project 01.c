
#include <stdio.h>
#include <string.h>

// Define the product structure
struct Product {
    int id;
    char name[50];
    int quantity;
    float cost_price;
    float selling_price;
};

// Global array to store products
struct Product inventory[100];
int product_count = 0;
float total_sales = 0, total_cost = 0;

// Function to add a new product
void addProduct() {
    printf("\n--- Add New Product ---\n");
    struct Product p;
    printf("Enter Product ID: ");
    scanf("%d", &p.id);
    printf("Enter Product Name: ");
    scanf(" %[^\n]%*c", p.name); // Read string with spaces
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Cost Price: ");
    scanf("%f", &p.cost_price);
    printf("Enter Selling Price: ");
    scanf("%f", &p.selling_price);
    inventory[product_count++] = p;
    printf("Product added successfully!\n");
}

// Function to display all products
void displayInventory() {
    printf("\n--- Inventory ---\n");
    if (product_count == 0) {
        printf("No products available.\n");
        return;
    }
    printf("%-5s %-20s %-10s %-10s %-10s\n", "ID", "Name", "Quantity", "Cost Price", "Sell Price");
    for (int i = 0; i < product_count; i++) {
        printf("%-5d %-20s %-10d %-10.2f %-10.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity,
               inventory[i].cost_price, inventory[i].selling_price);
    }
}

// Function to record a sale
void recordSale() {
    printf("\n--- Record Sale ---\n");
    int id, quantity;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    printf("Enter Quantity Sold: ");
    scanf("%d", &quantity);

    for (int i = 0; i < product_count; i++) {
        if (inventory[i].id == id) {
            if (inventory[i].quantity < quantity) {
                printf("Insufficient stock!\n");
                return;
            }
            inventory[i].quantity -= quantity;
            float sale_amount = quantity * inventory[i].selling_price;
            float cost_amount = quantity * inventory[i].cost_price;
            total_sales += sale_amount;
            total_cost += cost_amount;
            printf("Sale recorded successfully! Sale Amount: %.2f\n", sale_amount);
            return;
        }
    }
    printf("Product not found!\n");
}

// Function to calculate profits
void calculateProfit() {
    printf("\n--- Profit Report ---\n");
    printf("Total Sales: %.2f\n", total_sales);
    printf("Total Cost: %.2f\n", total_cost);
    printf("Profit: %.2f\n", total_sales - total_cost);
}

// Main menu
int main() {
    int choice;
    do {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Record Sale\n");
        printf("4. Calculate Profit\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                recordSale();
                break;
            case 4:
                calculateProfit();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

RESULT.......
  
--- Inventory Management System ---
1. Add Product
2. Display Inventory
3. Record Sale
4. Calculate Profit
5. Exit
Enter your choice: 
