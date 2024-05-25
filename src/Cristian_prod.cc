#include "Cristian_prod.h"

//  отрисовка
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
                              gpointer user_data) {
  std::vector<std::unique_ptr<Shape>> *shapes =
      static_cast<std::vector<std::unique_ptr<Shape>> *>(user_data);

  for (const auto &shape : *shapes) {
    shape->draw(cr);
  }

  return FALSE;
}

// Функция активации приложения
static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *drawing_area;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Shapes");
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

  drawing_area = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), drawing_area);

  g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event),
                   user_data);

  gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  std::vector<std::unique_ptr<Shape>> shapes;
  shapes.push_back(std::make_unique<Circle>(250, 60, 35));
  shapes.push_back(std::make_unique<Square>(350, 60, 80));
  shapes.push_back(std::make_unique<Triangle>(450, 100, 80));
  shapes.push_back(std::make_unique<Rectangle>(400, 150, 150, 50));

  app = gtk_application_new("gtk.identific.app", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), &shapes);

  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
