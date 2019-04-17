/*
 ******************************************************************************
 Project:      OWA EPANET
 Version:      2.2
 Module:       demand.c
 Description:  data for demand pattern list
 Authors:      see AUTHORS
 Copyright:    see AUTHORS
 License:      see LICENSE
 Last Updated: 04/12/2019
 ******************************************************************************
*/

#include <stdlib.h>
#include <string.h>

#include "demand.h"


typedef struct demand_data_s
{
  double base_demand;
  int    pattern_index;
  char   *category_name;
} demand_data_t;


demand_data_t *create_demand_data(double base_demand, int pattern_index, char *category_name)
{
    demand_data_t *demand_data = (demand_data_t *)malloc(sizeof(demand_data_t));

    demand_data->base_demand = base_demand;
    demand_data->pattern_index = pattern_index;

    if (cat_name)
        demand_data->category_name = strdup(cat_name);
    else
        demand_data->category_name = NULL;

    return demand_data;
}

void delete_demand_data(void *data)
{
    demand_data_t *demand_data = *(demand_data_t **)data;

    if (demand_data->category_name)
        free(demand_data->category_name);

	free(demand_data);
}

size_t get_demand_data_size(void)
{
	return sizeof(demand_data_t *);
}

demand_data_t *get_demand_data(list_node_t *lnode)
{
    return *(demand_data_t **)get_data(lnode);
}


bool convert_units(list_node_t *lnode, double unit_conversion)
{
	demand_data_t *demand_data = get_demand_data(lnode);
	double base_demand = get_base_demand(demand_data);

	set_base_demand(demand_data, base_demand/unit_conversion);
}


double get_base_demand(demand_data_t *data)
{
	return get_demand_data(lnode)->base_demand;
}

void set_base_demand(list_node_t *lnode, double base_demand)
{
	get_demand_data(lnode)->base_demand = base_demand;
}

int get_pattern_index(list_node_t *lnode)
{
    return get_demand_data(lnode)->pattern_index;
}

void set_pattern_index(list_node_t *lnode, int pattern_index)
{
	get_demand_data(lnode)->pattern_index = pattern_index;
}

char *get_category_name(list_node_t *lnode)
{
    return get_demand_data(lnode)->category_name;
}

void set_category_name(list_node_t *lnode, char *category_name)
{
	get_demand_data(lnode)->category_name = strdup(category_name);
}
