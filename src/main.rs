use gtk4::{glib, prelude::*};

fn main() {
    gtk4::init().unwrap();

    let dialog = gtk4::FileChooserDialog::new(
        Some("Open file"),
        gtk4::Window::NONE,
        gtk4::FileChooserAction::Open,
        &[("Open", gtk4::ResponseType::Accept)]
    );

    // Adding this option works fine.
    println!("Adding choice with no options...");
    dialog.add_choice("boolean", "Boolean", &[]);

    // Adding this one causes a segfault.
    println!("Adding choice with two options...");
    dialog.add_choice("option", "Options", &[("one", "One"), ("two", "Two")]);

    println!("Presenting dialog...");
    dialog.present();

    println!("Running main loop...");
    let main_loop = glib::MainLoop::new(None, false);
    let quit_handle = main_loop.clone();
    dialog.connect_response(move |_, _| quit_handle.quit());
    main_loop.run();
}
