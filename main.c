#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Recipe{
    char name[66];
    char ingredients[500];
    char instructions[500];
};
 void addRecipe(){
    FILE *fp;
    struct Recipe r;
    fp=fopen("recipes.text","a");
    if(fp==NULL){
        printf("Error opening file!");
        return;
    }
    printf("Enter the name of your recipe:");
    fgets(r.name, sizeof(r.name), stdin);
    r.name[strcspn(r.name,"\n")] = 0;
    printf("Enter the ingredients of your recipe:");
    fgets(r.ingredients, sizeof(r.ingredients), stdin);
    r.ingredients[strcspn(r.ingredients,"\n")] = 0;
    printf("Enter the instructions of your recipe:");
    fgets(r.instructions, sizeof(r.instructions), stdin);
    r.instructions[strcspn(r.instructions,"\n")] = 0;
    fprintf(fp,"Recipe Name: %s\nIngredients: %s\nInstructions: %s\n",r.name,r.ingredients,r.instructions);

    fclose(fp);
    printf("Recipe added successfully!\n");
 }
 void clearRecipes() {
    FILE *fp;

    fp = fopen("recipes.text","w");

    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }

    fclose(fp);

    printf("All recipes deleted successfully!\n");
}
    void viewRecipes(){
        FILE *fp;
        char ch;
        fp=fopen("recipes.text","r");
        if(fp==NULL){
            printf("Error opening file!");
            return;
        }
        while((ch=fgetc(fp))!=EOF){
            putchar(ch);
        }
        fclose(fp);
    }
    void searchRecipe(){
        FILE *fp;
        struct Recipe r;
        char searchName[66];
        char line[660];
        int found=0;
        fp=fopen("recipes.text","r");
        if(fp==NULL){
            printf("Error opening file!");
            return;
        }
        printf("Enter the name of the recipe you want to search:");
        fgets(searchName, sizeof(searchName), stdin);
            while(fgets(line, sizeof(line), fp)){
        if(strstr(line, searchName)){
            printf("\nRecipe Found:\n");
            printf("%s", line);

            fgets(line, sizeof(line), fp);
            printf("%s", line);

            fgets(line, sizeof(line), fp);
            printf("%s", line);
           
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Recipe not found.\n");
    }

    fclose(fp);

    }
    void deleteRecipe(){
        FILE *fp, *temp;
       
        char searchName[66];
        char line[660];
        int found=0;
        fp=fopen("recipes.text","r");
        temp=fopen("temp.text","w");
        if(fp==NULL || temp==NULL){
            printf("Error opening file!");
            return;
        }
        printf("Enter the name of the recipe you want to delete:");
        fgets(searchName, sizeof(searchName), stdin);
            while(fgets(line, sizeof(line), fp)){
        if(strstr(line, searchName)){
            printf("\nRecipe Found and Deleted:\n");
            printf("%s", line);

            fgets(line, sizeof(line), fp);
            printf("%s", line);

            fgets(line, sizeof(line), fp);
            printf("%s", line);

            found = 1;
            continue; 
        }
        fprintf(temp, "%s", line); 
    }
    fclose(fp);
    fclose(temp);
    remove("recipes.text");
    rename("temp.text", "recipes.text");}
int main(){
    int choice;
    while(1){
        printf("                        ================================================\n");

        printf("                                     Recipe Management System\n");
        printf("                        ================================================\n");
        printf("\n");
         printf("                       ._._._._._._What would you like to do?._._._._._._\n");
        printf("                        1. Add a recipe\n");
        printf("                        2. View all recipes\n");
        printf("                        3. Search for a recipe\n");
        printf("                        4. Delete a recipe\n");
        printf("                        5. Clear all recipes\n");

            printf("                        6. Exit\n");
        printf("                        Enter your choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1:
                addRecipe();
                break;
            case 2:
                viewRecipes();
                break;
            case 3:
                searchRecipe();
                break;
            case 4:
                deleteRecipe();
                break;
            case 5:
                clearRecipes();
                break;
            case 6: 
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
