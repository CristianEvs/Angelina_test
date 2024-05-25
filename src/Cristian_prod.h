#include <gtk/gtk.h>
#include <memory>
#include <vector>

// Базовый класс фигуры
class Shape {
 public:
  virtual void draw(cairo_t *cr) const = 0;
  virtual ~Shape() = default;
};

class Circle : public Shape {
 public:
  Circle(double x, double y, double radius) : x(x), y(y), radius(radius) {}
  void draw(cairo_t *cr) const override {
    cairo_set_source_rgba(cr, 1.0, 0.0, 0.0, 1.0);
    cairo_arc(cr, x, y, radius, 0, 2 * G_PI);
    cairo_stroke(cr);
  }

 private:
  double x, y, radius;
};

class Square : public Shape {
 public:
  Square(double x, double y, double size) : x(x), y(y), size(size) {}
  void draw(cairo_t *cr) const override {
    cairo_set_source_rgba(cr, 5.0, 0.0, 4.0, 8.0);
    cairo_rectangle(cr, x, y, size, size);
    cairo_stroke(cr);
  }

 private:
  double x, y, size;
};

class Triangle : public Shape {
 public:
  Triangle(double x, double y, double size) : x(x), y(y), size(size) {}
  void draw(cairo_t *cr) const override {
    cairo_set_source_rgba(cr, 0.0, 0.0, 1.0, 1.0);
    cairo_move_to(cr, x, y);
    cairo_line_to(cr, x + size, y);
    cairo_line_to(cr, x + size / 2, y - size);
    cairo_close_path(cr);
    cairo_stroke(cr);
  }

 private:
  double x, y, size;
};

class Rectangle : public Shape {
 public:
  Rectangle(double x, double y, double width, double height)
      : x(x), y(y), width(width), height(height) {}
  void draw(cairo_t *cr) const override {
    cairo_set_source_rgba(cr, 0.0, 1.0, 0.0, 1.0);
    cairo_rectangle(cr, x, y, width, height);
    cairo_stroke(cr);
  }

 private:
  double x, y, width, height;
};