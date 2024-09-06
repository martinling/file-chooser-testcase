#include <gtk/gtk.h>
#include <stdio.h>

static GMainLoop *main_loop;

void quit(GtkWidget *dialog, gpointer user_data) {
    g_main_loop_quit(main_loop);
}

int main(int argc, char **argv) {
    gtk_init();

    GtkWidget *dialog = gtk_file_chooser_dialog_new(
        "Open file",
        NULL,
        GTK_FILE_CHOOSER_ACTION_OPEN,
        "Open",
        GTK_RESPONSE_ACCEPT,
        NULL
    );

    printf("Adding choice with no options...\n");
    gtk_file_chooser_add_choice(
        GTK_FILE_CHOOSER(dialog),
        "boolean",
        "Boolean",
        NULL,
        NULL
    );

    const char *options[] = {"one", "two", NULL};
    const char *option_labels[] = {"One", "Two", NULL};

    printf("Adding choice with two options...\n");
    gtk_file_chooser_add_choice(
        GTK_FILE_CHOOSER(dialog),
        "options",
        "Options",
        options,
        option_labels
    );

    printf("Presenting dialog...\n");
    gtk_window_present(GTK_WINDOW(dialog));

    //printf("Starting main loop...\n");
    main_loop = g_main_loop_new(NULL, false);
    g_signal_connect(dialog, "response", G_CALLBACK(quit), NULL);
    g_main_loop_run(main_loop);

    return 0;
}
