/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:41:33 by jrim              #+#    #+#             */
/*   Updated: 2022/09/18 15:00:54 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_obj    *object_init(t_obj_type type, void *element, t_rgb albedo)
{
    t_obj    *new;

    if (!(new = (t_obj *)malloc(sizeof(t_obj))))
        return (NULL);
    new->type = type;
    new->element = element;
    new->albedo = albedo;
    new->next = NULL;
    return (new);
}

t_sph    *sphere_init(t_pt center, double radius)
{
    t_sph *sph;

    if(!(sph = (t_sph *)malloc(sizeof(t_sph))))
        return (NULL);
    sph->center = center;
    sph->rad = radius;
    sph->rad_sq = radius * radius;
    return (sph);
}

t_plane *plane_init(t_pt center, t_vt dir)
{
    t_plane *pln;

    if (!(pln = (t_plane *)malloc(sizeof(t_plane))))
        return (NULL);
    pln->center = center;
    pln->dir = vt_unit(dir);
    return (pln);
}

t_cyl *cyl_init(t_pt center, t_vt dir, double diam, double height)
{
    t_cyl *cyl;

    if (!(cyl = (t_cyl *)malloc(sizeof(t_cyl))))
        return (NULL);
    cyl->point = center;
    cyl->normal = vt_unit(dir);
    cyl->diameter = diam;
    cyl->height = height;
    cyl->rad = cyl->diameter / 2;
	cyl->cap_top = vt_plus(cyl->point, vt_multi(cyl->normal, cyl->height / 2));
	cyl->cap_bot = vt_plus(cyl->point, vt_multi(cyl->normal, -(cyl->height / 2)));
    return (cyl);
}

// t_cyl *cyl_init(t_pt center, t_vt dir, double diam, double height)
// {
//     t_cyl *cyl;

//     if (!(cyl = (t_cyl *)malloc(sizeof(t_cyl))))
//         return (NULL);
//     cyl->center = center;
//     cyl->dir = vt_unit(dir);
//     cyl->diam = diam;
//     cyl->height = height;
//     cyl->rad = cyl->diam / 2;
// 	cyl->cap_top = vt_plus(cyl->center, vt_multi(cyl->dir, cyl->height / 2));
// 	cyl->cap_bot = vt_plus(cyl->center, vt_multi(cyl->dir, -(cyl->height / 2)));
//     return (cyl);
// }

t_light *light_point(t_pt orig, t_rgb color, double bright_ratio)
{
    t_light *light;

    if(!(light = (t_light *)malloc(sizeof(t_light))))
        return (NULL);
    light->orig = orig;
    light->light_color = color;
    light->bright_ratio = bright_ratio;
    return (light);
}