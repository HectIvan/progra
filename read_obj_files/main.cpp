#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <sstream>

int main()
{
	// vectors needed
	std::vector<float> m_vertices;
	std::vector<float> m_normals;
	std::vector<float> UVCoords;
	std::vector<unsigned short> m_indicesVert;
	std::vector<unsigned short> m_indicesNorm;
	std::vector<unsigned short> m_indicesUV;


	// ask for file name
	std::string name_of_file;
	std::cout << "enter the name of the file (type of file required in name): ";
	std::cin >> name_of_file;

	// open file
	std::ifstream binary_file(name_of_file, std::ios::binary);
	if (!binary_file) // if file cannot be opened -/- does not exist
	{
		std::cout << "ERROR::progra::read_obj_files::main.cpp: Failed to load binary file" << std::endl;
		return 1;
	}
	std::string line_to_analyze;
	std::string conversion;

	while (!binary_file.eof()) // while the enf od the file is not found
	{
		getline(binary_file, line_to_analyze); // gets line
		if (line_to_analyze[0] == 'v' && line_to_analyze[1] == ' ') // if it is a vertex line
		{
			conversion = "";
			for (int i = 1; i < line_to_analyze.size(); ++i)
			{
				if (line_to_analyze[i] != ' ')
				{
					char conv = line_to_analyze[i];
					conversion += conv;
				}
				else
				{
					if (line_to_analyze[i] == ' ' && conversion != "")
					{
						float new_vertex = std::stof(conversion);
						m_vertices.push_back(new_vertex);
						conversion = "";
					}
				}
			}
		}

		if (line_to_analyze[0] == 'v' && line_to_analyze[1] == 'n') // if it is a vertex line
		{
			conversion = "";
			for (int i = 1; i < line_to_analyze.size(); ++i)
			{
				if (line_to_analyze[i] != ' ')
				{
					char conv = line_to_analyze[i];
					conversion += conv;
				}
				else
				{
					if (line_to_analyze[i] == ' ' && conversion != "")
					{
						float new_vertex = std::stof(conversion);
						m_normals.push_back(new_vertex);
						conversion = "";
					}
				}
			}
		}
		// ERRRORES ???????????????????????????????
		//if (line_to_analyze[0] == 'v' && line_to_analyze[1] == 'n') // if it is a vertex line
		//{
		//	conversion = "";
		//	for (int i = 1; i < line_to_analyze.size(); ++i)
		//	{
		//		if (line_to_analyze[i] != ' ')
		//		{
		//			char conv = line_to_analyze[i];
		//			conversion += conv;
		//		}
		//		else
		//		{
		//			if (line_to_analyze[i] == ' ' && conversion != "")
		//			{
		//				float new_vertex = std::stof(conversion);
		//				m_normals.push_back(new_vertex);
		//				conversion = "";
		//			}
		//		}
		//	}
		//}

		if (line_to_analyze[0] == 'f' && line_to_analyze[1] == ' ') // if it is a vertex line
		{
			conversion = "";
			for (int i = 1; i < line_to_analyze.size(); ++i)
			{
				if (line_to_analyze[i] != ' ')
				{
					if (line_to_analyze[i] != '/')
					{
						char conv = line_to_analyze[i];
						conversion += conv;
					}
					else
					{
						if (conversion != "")
						{
							float new_vertex = std::stof(conversion);
							UVCoords.push_back(new_vertex);
							conversion = "";
						}
					}
				}
				else
				{
					if (conversion != "")
					{
						float new_vertex = std::stof(conversion);
						UVCoords.push_back(new_vertex);
						conversion = "";
					}
				}
			}
		}
	}
	std::cout << "number of vertex: " << m_vertices.size() << std::endl;
	std::cout << "number of normal vertex: " << m_normals.size() << std::endl;
	std::cout << "number of faces: " << UVCoords.size() << std::endl;
	/*int management = 1;
	for (int i = 0; i < UVCoords.size(); ++i)
	{
		if (management == 1)
		{
			std::cout << "f ";
		}
		if (management != 7)
		{
			std::cout << UVCoords[i] << " ";
			++management;
		}
		if (management == 7)
		{
			management = 1;
			std::cout<< std::endl;
		}
	}*/

	if (0 == m_vertices.size())
	{
		std::cout << std::endl << "ERROR::progra::read_obj_files::main.cpp: File missing vertex" << std::endl;
	}
	if (0 == m_normals.size())
	{
		std::cout << std::endl << "ERROR::progra::read_obj_files::main.cpp: File missing normal vertex" << std::endl;
	}
	if (0 == UVCoords.size())
	{
		std::cout << std::endl << "ERROR::progra::read_obj_files::main.cpp: File missing UV coordenates" << std::endl;
	}

	return 0;
}