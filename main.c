#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Vehicle {
    char plateNumber[20];
    int type;
};

struct Transaction {
    struct Vehicle vehicle;
    float fee;
};


float calculateFee(int vehicleType) {

    switch (vehicleType) {
        case 1:
            return 2.5;
        case 2:
            return 5.0;

        default:
            return 0.0;
    }
}


void vehicleEntry(struct Vehicle *vehicle) {
    printf("Enter the vehicle plate number: ");
    scanf("%s", vehicle->plateNumber);

    printf("Enter the vehicle type (1 for car, 2 for truck, etc.): ");
    scanf("%d", &vehicle->type);

    printf("Vehicle entry is recorded successfully!\n");
}


struct Transaction vehicleExit(struct Vehicle vehicle) {
    struct Transaction transaction;
    transaction.vehicle = vehicle;
    transaction.fee = calculateFee(vehicle.type);

    printf("Vehicle exit is recorded successfully!\n");
    printf("Toll Fee: $%.2f\n", transaction.fee);

    return transaction;
}


void displayTransactionHistory(struct Transaction *history, int count) {
    printf("\nTransaction History:\n");
    printf("------------------------------------------------\n");
    printf("| %-15s | %-10s | %-7s |\n", "Plate Number", "Vehicle Type", "Fee");
    printf("------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("| %-15s | %-10d | $%-6.2f |\n", history[i].vehicle.plateNumber,
               history[i].vehicle.type, history[i].fee);
    }

    printf("------------------------------------------------\n");
}


void automatedTollCollection() {
    struct Vehicle vehicle;
    struct Transaction transaction;


    strcpy(vehicle.plateNumber, "ABC123");
    vehicle.type = 1;

    vehicleEntry(&vehicle);
    transaction = vehicleExit(vehicle);


    printf("Automated Toll Collection Completed.\n");
}


void vehicleClassification(struct Vehicle vehicle) {

    printf("Vehicle Classification:\n");
    printf("Plate Number: %s\n", vehicle.plateNumber);
    printf("Vehicle Type: %d\n", vehicle.type);
}

int main() {
    struct Vehicle currentVehicle;
    struct Transaction transactionHistory[100];
    int transactionCount = 0;

    int choice;
    do {
        printf("\nToll Management System\n");
        printf("1. Vehicle Entry\n");
        printf("2. Vehicle Exit\n");
        printf("3. Display Transaction History\n");
        printf("4. Automated Toll Collection\n");
        printf("5. Vehicle Classification\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vehicleEntry(&currentVehicle);
                break;
            case 2:
                if (strlen(currentVehicle.plateNumber) > 0) {
                    transactionHistory[transactionCount++] = vehicleExit(currentVehicle);
                    memset(&currentVehicle, 0, sizeof(struct Vehicle));
                } else {
                    printf("Error: No vehicle entry found!\n");
                }
                break;
            case 3:
                displayTransactionHistory(transactionHistory, transactionCount);
                break;
            case 4:
                automatedTollCollection();
                break;
            case 5:
                if (strlen(currentVehicle.plateNumber) > 0) {
                    vehicleClassification(currentVehicle);
                } else {
                    printf("Error: No vehicle entry found!\n");
                }
                break;
            case 6:
                printf("Exiting Toll Management System.bye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
