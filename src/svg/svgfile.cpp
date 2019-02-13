#include "svgfile.h"
#include <iostream>
#include <sstream>


const std::string svgHeader =
    "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
    "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" ";

const std::string svgEnding = "\n\n</svg>\n";

/// Effets "Boule en relief", voir données à la fin de ce fichier
extern const std::string svgBallGradients;

std::set<std::string> Svgfile::s_openfiles;

bool Svgfile::s_verbose = true;

Svgfile::Svgfile(std::string _filename, int _width, int _height) :
    m_filename{_filename}, m_width{_width}, m_height{_height}
{
    if (s_verbose)
        std::cout << "Opening SVG output file : "
                  << m_filename << std::endl;

    if ( s_openfiles.count(m_filename) )
        throw std::runtime_error( "File " + m_filename + " already open !" );

    m_ostrm.open(m_filename);
    s_openfiles.insert(m_filename);
    if (!m_ostrm)
    {
        std::cout << "Problem opening " << m_filename << std::endl;
        throw std::runtime_error("Could not open file " + m_filename );
    }

    if (s_verbose)
        std::cout << "OK" << std::endl;

    // Writing the header into the SVG file
    m_ostrm << svgHeader;
    m_ostrm << "width=\"" << m_width << "\" height=\"" << m_height << "\">\n\n";

}

void Svgfile::commencer()
{





}

void Svgfile::finir()
{
    //m_ostrm << "</svg>"
      //      <<"\n";
}
void Svgfile::eraseS()
{
   //s_openfiles.erase(m_filename);

}

Svgfile::~Svgfile()
{
    // Writing the ending into the SVG file
    m_ostrm << svgEnding;

    // Removing this file from the list of open files
    s_openfiles.erase(m_filename);

    // No need to explicitly close the ofstream object (automatic upon destruction)
}

// Helper templated function
template<typename T>
std::string attrib(std::string name, T val)
{
    std::ostringstream oss;
    oss << name << "=\"" << val << "\" ";
    return oss.str();
}

void Svgfile::addDisk(double x, double y, double r, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", color )
            << "/>\n";
}

void Svgfile::addCircle(double x, double y, double r, double ep, std::string color)
{
    m_ostrm << "<circle "
            << attrib("cx", x)
            << attrib("cy", y)
            << attrib("r",  r)
            << attrib("fill", "none")
            << attrib("stroke", color )
            << attrib("stroke-width", ep )
            << "/>\n";
}

void Svgfile::addEllipse(double cx, double cy, double rx, double ry, std::string color)
{
    m_ostrm << "<ellipse "
            << attrib("cx", cx)
            << attrib("cy", cy)
            << attrib("rx",  rx)
            << attrib("ry", ry)
            << attrib("fill", color)
            << "/>\n";
}

void Svgfile::degrade(std::string nomGrad,std::string c,std::string c1)
{
    m_ostrm<< "<defs>\n"
            <<"<linearGradient \n"
           << attrib ("id",nomGrad)
           << attrib ("x1","0%")
           << attrib ("y1","30%")
           << attrib ("x2","0%")
           << attrib ("y2","5%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("stop-color",c)
           <<attrib ("stop-opacity","1")<< "/>"
           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("stop-color",c1)
           <<attrib ("stop-opacity","1")<< "/>"
        <<"\n</linearGradient> \n"
        << "</defs>\n\n";
}

void Svgfile::addRadialDegrade(std::string nomGrad,std::string c,std::string c1)
{
    m_ostrm<< "<defs>\n"
            <<"<radialGradient \n"
           << attrib ("id",nomGrad)
           << attrib ("cx","50%")
           << attrib ("cy","50%")
           << attrib ("r","50%")
           << attrib ("fx","50%")
           << attrib ("fy","50%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("stop-color",c)
           <<attrib ("stop-opacity","1")<< "/>"

           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("stop-color",c1)
           <<attrib ("stop-opacity","1")<< "/>"
        <<"\n</radialGradient> \n"
        << "</defs>\n\n";
}

void Svgfile::addEllipseTransp(double cx, double cy, double rx, double ry, std::string color,double transp)
{
    m_ostrm<< "<defs>\n"
            <<"<radialGradient \n"
           << attrib ("id","grad147892")
           << attrib ("cx","50%")
           << attrib ("cy","50%")
           << attrib ("r","50%")
           << attrib ("fx","50%")
           << attrib ("fy","50%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("stop-color",color)
           <<attrib ("stop-opacity",transp)<< "/>"

           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("stop-color",color)
           <<attrib ("stop-opacity",transp)<< "/>"
        <<"\n</radialGradient> \n"
        << "</defs>\n\n";
        addEllipse(cx,cy,rx,ry,"url(#grad147892)");


}

/// <polygon points="200,10 250,190 160,210" style="fill:lime;stroke:purple;stroke-width:1" />
void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill,
                          double thickness, std::string colorStroke)
{

    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << ";stroke:" << colorStroke
            << ";stroke-width:" << thickness
            << "\" />\n";
}


void Svgfile::addTriangle(double x1, double y1, double x2, double y2,
                          double x3, double y3, std::string colorFill)
{
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3
            << "\" style=\"fill:" << colorFill
            << "\" />\n";
}

void Svgfile::addPolygone(double x1, double y1, double x2, double y2,
                          double x3, double y3, double x4, double y4, std::string colorFill)
{

    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3 << " "
            << x4 << "," << y4
            << "\" style=\"fill:" << colorFill
            << "\" />\n";
}

void Svgfile::addPolygoneTransp(double x1, double y1, double x2, double y2,
                          double x3, double y3, double x4, double y4, std::string colorFill,double transp)
{
    m_ostrm<< "<defs>\n"
            <<"<radialGradient \n"
           << attrib ("id","grad147892333")
           << attrib ("cx","50%")
           << attrib ("cy","50%")
           << attrib ("r","50%")
           << attrib ("fx","50%")
           << attrib ("fy","50%") << ">"
           <<"\n<stop "
           <<attrib ("offset","0%")
           <<attrib ("stop-color",colorFill)
           <<attrib ("stop-opacity",transp)<< "/>"

           <<" \n<stop "
           <<attrib ("offset","100%")
        <<attrib ("stop-color",colorFill)
           <<attrib ("stop-opacity",transp)<< "/>"
        <<"\n</radialGradient> \n"
        << "</defs>\n\n";
    m_ostrm << "<polygon points=\" "
            << x1 << "," << y1 << " "
            << x2 << "," << y2 << " "
            << x3 << "," << y3 << " "
            << x4 << "," << y4
            << "\" style=\"fill:" << "url(#grad147892333)"
            << "\" />\n";
}

void Svgfile::addLine(double x1, double y1, double x2, double y2, std::string color)
{
    m_ostrm << "<line "
            << attrib("x1", x1)
            << attrib("y1", y1)
            << attrib("x2", x2)
            << attrib("y2", y2)
            << attrib("stroke", color)
            << "/>\n";
}

void Svgfile::addRectangle(double xBasGauche,double yBasGauche,double xHautDroite,double yHautDroite, std::string colorFill)
{
    addTriangle(xHautDroite,yHautDroite,xBasGauche,yHautDroite,xHautDroite,yBasGauche,colorFill);
    addTriangle(xBasGauche,yBasGauche,xBasGauche,yHautDroite,xHautDroite,yBasGauche,colorFill);
    addLine(xHautDroite,yBasGauche,xBasGauche,yHautDroite,colorFill);
}



void Svgfile::addMontain(double x1,double x2, double yBas,
                          double x3,double x4, double yHaut,
                          double rySommet, std::string colorFill)
{

    addEllipse((x4+x3)/2,yHaut*1.008,((x4+x3)/2)-x3,rySommet,colorFill);
    m_ostrm << "<polygon points=\" "
            << x2 << "," << yBas << " "
            << x1 << "," << yBas << " "
            << x3 << "," << yHaut << " "
            << x4 << "," << yHaut << " "
            << "\" style=\"fill:" << colorFill
            << "\" />\n";
}

void Svgfile::addCross(double x, double y, double span, std::string color)
{
    addLine(x-span, y-span, x+span, y+span, color);
    addLine(x-span, y+span, x+span, y-span, color);
}

void Svgfile::addText(double x, double y, std::string text, std::string color)
{
    /// <text x="180" y="60">Un texte</text>
    m_ostrm << "<text "
            << attrib("x", x)
            << attrib("y", y)
            << attrib("fill", color)
            << ">" << text << "</text>\n";
}

void Svgfile::addText(double x, double y, double val, std::string color)
{
    std::ostringstream oss;
    oss << val;
    addText(x, y, oss.str(), color);
}

void Svgfile::addGrid(double span, bool numbering, std::string color)
{
    double y=0;
    while (y<=m_height)
    {
        addLine(0, y, m_width, y, color);
        if (numbering)
            addText(5, y-5, y, color);
        y+=span;
    }

    double x=0;
    while (x<=m_width)
    {
        addLine(x, 0, x, m_height, color);
        if (numbering)
            addText(x+5, 15, x, color);
        x+=span;
    }
}

std::string Svgfile::makeRGB(int r, int g, int b)
{
    std::ostringstream oss;
    oss << "rgb(" << r << "," << g << "," << b << ")";
    return oss.str();
}
